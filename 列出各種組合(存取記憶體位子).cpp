#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h> //�h������禡�w
#include <time.h>
#include <math.h>
#include <windows.h>

char st[1000];

int getstringlength(char *s);
void down_(int *loadnum);
void down_d(int num,int data2,int *s,int *numbox);
void create_data(char *s,char chr);

int main()
{
	int num1=1000;
	fclose(fopen("test.txt","w"));
	printf("�п�J�Ʀr");
	scanf("%s",st);
	num1 = getstringlength(st);
	for(int loopnum1=num1-1;loopnum1 >= 0;loopnum1--){
		int c[(num1+1)*2+1];
		c[0] = num1-2;
		c[1] = num1;
		c[2] = num1+3;
		c[(num1+1)*2]=loopnum1;
		for(int loopnum2 = 0;loopnum2 < num1;loopnum2++){
			c[loopnum2+3] = st[loopnum2];
		}
		//_beginthread(down_,0,c);
		down_(c);
	}	
}

void down_d(int num,int data2,int *s,int *numbox){
	if(num != -1){
		for(int loopnum2=data2-1;loopnum2 >= 0;loopnum2--){
			for(int loopnum4=num+1;loopnum4 <= data2-1;loopnum4++){
				if(*(s+loopnum4)!=loopnum2){
					if(loopnum4 == data2-1){ 
						*(s+num)=loopnum2;
						down_d(num-1,data2,s,numbox);
					} 
				}else{
					break;
				}
			}	
		}
	}else{
		char str[data2];
		str[0] = *(numbox+*(s+data2-1));
		str[1] = '\0';
		char file[getstringlength(str)+10];
		file[0] = '\0';
		strcat(file, "test_");
		strcat(file, str);
		strcat(file, ".txt");
		for(int loopnum3=data2-1;loopnum3 >= 0;loopnum3--){
			
			create_data(file,*(numbox+*(s+loopnum3)));
		}
		create_data(file,'\n');
	}
}

void down_(int *loadnum){
	int data1 = *loadnum;
	int data2 = *loadnum+1;
	int data3 = *loadnum+2;
	int *s1,*s2;
	s1=loadnum+3;
	s2=loadnum+data3;
	
	char str[data2];
	str[0] = st[*(s2+1+data2-1)];
	str[1] = '\0';
	char file[getstringlength(str)+10];
	file[0] = '\0';
	strcat(file, "test_");
	strcat(file, str);
	strcat(file, ".txt");
	fclose(fopen(file,"w"));
	
	down_d(data1,data2,s2,s1);
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

void create_data(char *s,char chr){
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
