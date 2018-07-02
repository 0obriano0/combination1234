#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>

char st[1000];
char buffer;
int num1=1000;

int getstringlength(char *s);
void down(int num,char *s);
void create_data(char *s,char chr);

int main()
{
	fopen("test.txt","w");
	printf("請輸入數字");
	scanf("%s",st);
	num1 = getstringlength(st);
	for(int loopnum1=num1-1;loopnum1 >= 0;loopnum1--){
		char c[num1];
		c[num1-1]=loopnum1;
		down(num1-2,c);
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
			printf("無法開啟檔案");
			return 0;
	}else{
		fprintf(pf,"%c",chr);
		fclose(pf);
	}
}
