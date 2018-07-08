#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h> //�h������禡�w
#include <time.h>
#include <math.h>
#include <windows.h>

int getstringlength(char *s);
void down_(int *loadnum);
void down_d(int num,int data2,char *s,int *numbox,int *data_run);
int create_data(char *s,char chr);
void int2str(int i, char *s);

int main()
{
	char st[100];
	int num1=1000;
	printf("�п�J���(�̦h�u���J100�ӭ�):");
	scanf("%s",st);
	num1 = getstringlength(st);
	int *c;
	int *ptr[100];
	long clk_start = clock()/CLOCKS_PER_SEC; //��J�{�������{�b���ɶ�
	for(int loopnum1=num1-1;loopnum1 >= 0;loopnum1--){
		do{
			c = (int)malloc(sizeof(int)*((num1+1)*2+2));
		}while(c==NULL);
		*c = num1-2;
		*(c+1) = num1;
		*(c+2) = num1+3;
		*(c+((num1+1)*2))=loopnum1;
		*(c+((num1+1)*2+1))=0;
		printf("c[%d] = %p\n",loopnum1,c+((num1+1)*2+1));
		ptr[loopnum1] = c; 
		for(int loopnum2 = 0;loopnum2 < num1;loopnum2++){
			*(c+loopnum2+3) = st[loopnum2]-'0';
		}
		_beginthread(down_,0,c);
		//down_(c);
	}
	bool thread_all_finish = false;
	int thread_data_length = 1;
	for(int loopnum2=num1-1;loopnum2 >= 1;loopnum2--){
		thread_data_length*=loopnum2;
	}
	while(!thread_all_finish){
		//printf("thread_data_length = %d \n",thread_data_length);
		for(int loopnum3=num1-1;loopnum3 >= 0;loopnum3--){
			//printf("ptr[%d] = %d �O���� = %p\n",loopnum1,*(ptr[loopnum1]+((num1+1)*2)+1),ptr[loopnum1]+((num1+1)*2)+1);
			if(*(ptr[loopnum3]+((num1+1)*2)+1) == thread_data_length){
				thread_all_finish = true;
			}else{
				thread_all_finish = false;
				break;
			}
		}
	}
	long clk_end;
	clk_end = clock()/CLOCKS_PER_SEC - clk_start;
	fprintf(stderr,"���ծɶ�: %d ��\n",clk_end);
	for(int loopnum4=num1-1;loopnum4 >= 0;loopnum4--)
		free(ptr[loopnum4]);
	system("pause");
}

void down_d(int num,int data2,char *st,int *s,int *data_run){
	if(num != -1){
		for(int loopnum2=data2-1;loopnum2 >= 0;loopnum2--){
			for(int loopnum4=num+1;loopnum4 <= data2-1;loopnum4++){
				if(*(s+loopnum4)!=loopnum2){
					if(loopnum4 == data2-1){ 
						*(s+num)=loopnum2;
						down_d(num-1,data2,st,s,data_run);
					} 
				}else{
					break;
				}
			}	
		}
	}else{
		char str[100];
    	int2str(*(s+data2-1)+1, str);
		char file[getstringlength(str)+16];
		file[0] = '\0';
		strcat(file, "data//test_");
		strcat(file, str);
		strcat(file, ".txt");
		for(int loopnum3=data2-1;loopnum3 >= 0;loopnum3--){
			create_data(file,st[*(s+loopnum3)]);
		}
		create_data(file,'\n');
		*data_run += 1;
		printf("data_run[%d] = %d �O���� = %p\n",*(s+data2-1)+1,*data_run,data_run);
	}
}

void down_(int *loadnum){
	int data1 = *loadnum;
	int data2 = *(loadnum+1);
	int data3 = *(loadnum+2);
	int *data4 = (loadnum+((data2+1)*2+1));
	int *s1;
	s1=loadnum+data3;
	char st[data2];
	for(int loopnum1 = 0;loopnum1 < data2;loopnum1++){
		st[loopnum1] = *(loadnum+3+loopnum1)+'0';
	}
	char str[100];
    int2str(*(s1+data2-1)+1, str);
	char file[getstringlength(str)+16];
	file[0] = '\0';
	strcat(file, "data//test_");
	strcat(file, str);
	strcat(file, ".txt");
	fclose(fopen(file,"w"));
	
	down_d(data1,data2,st,s1,data4);
}

int getstringlength(char *s){
	int num1 = 0;
	while(1){
		if(*(s+num1) == '\0')
			break;
		num1++;
	}
	return num1;
}

int create_data(char *s,char chr){
	FILE *pf;
	pf = fopen(s,"a");
	if(pf == NULL){
			printf("�L�k�}���ɮ�");
			return 0;
	}else{
		fprintf(pf,"%c",chr);
		fclose(pf);
	}
}

void int2str(int i, char *s){
	sprintf(s,"%d",i);
}
