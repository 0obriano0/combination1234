#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h> //�h������禡�w
#include <time.h>
#include <math.h>
#include <windows.h>

struct combination_data{ //�W�٬�student�����c
	int num;
	char *data;
};

char st[1000];
char buffer;
int num1=1000;

int getstringlength(char *s);
void down(int num,char *s);
void downs(combination_data *loaddata);
void create_data(char *s,char chr);

int main()
{
	fopen("test.txt","w");
	printf("�п�J�Ʀr");
	scanf("%s",st);
	num1 = getstringlength(st);
	for(int loopnum1=num1-1;loopnum1 >= 0;loopnum1--){
		combination_data loaddata;
		loaddata.num = num1;
		loaddata.data = new char[loaddata.num];
		*(loaddata.data+loaddata.num-1)=loopnum1;
		//down(loaddata.num-2,loaddata.data);
		downs(&loaddata);
	}	
} 

void down(int num,char *s){
	if(num != -1){
		for(int loopnum2=num1-1;loopnum2 >= 0;loopnum2--){
			for(int loopnum4=num+1;loopnum4 <= num1-1;loopnum4++){
				if(*(s+loopnum4)!=loopnum2){
					if(loopnum4 == num1-1){ 
						*(s+num)=loopnum2;
						down(num-1,s);
					} 
				}else{
					break;
				}
			}	
		}
	}else{
		for(int loopnum3=num1-1;loopnum3 >= 0;loopnum3--){
			create_data("test.txt",st[*(s+loopnum3)]);
		}
		create_data("test.txt",'\n');
	}
}

void downs(combination_data *loaddata){
	down((*loaddata).num-2,(*loaddata).data);
	//printf("%s     %d",(*loaddata).data,(*loaddata).num-2);
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
