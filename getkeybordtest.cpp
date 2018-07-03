#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
 /* int c1, c2;
     while (!kbhit()) ;
     c1 = getch();

     //c1= getche(kbhit());;
     printf("\n%d\n",c1);
     if (c1 == 0)
     {
     c2 = getch(); 
     //printf("c1=%d c2=%d",c1, c2);
     printf("c1=%#02x c2=%#02x",c1, c2);

     }
     else

     printf("ascii=%d\n",c1);
     printf("you input key is \"%c\"\n",c1); */
	int c1, c2;
	while(1){
		if (!kbhit())
			c1= getch();
		
		if (c1 == 0 || c1==224){
			c2 = getche();
			printf("\n");
			printf("c1=%d c2=%d\n",c1, c2);
			switch(c2){
				case 59:
				printf(" you press is \"F1\"\n");
				break;
				case 60:
				printf(" you press is \"F2\"\n");
				break;
				case 61:
				printf(" you press is \"F3\"\n");
				break;
				case 62:
				printf(" you press is \"F4\"\n");
				break;
				case 63:
				printf(" you press is \"F5\"\n");
				break;
				case 64:
				printf(" you press is \"F6\"\n");
				break;
				case 65:
				printf(" you press is \"F7\"\n");
				break;
				case 66:
				printf(" you press is \"F8\"\n");
				break;
				case 67:
				printf(" you press is \"F9\"\n");
				break;
				case 68:
				printf(" you press is \"F10\"\n");
				break;
				case 133:
				printf(" you press is \"F11\"\n");
				break;
				case 134:
				printf(" you press is \"F12\"\n");
				break;
				case 32:
				printf(" you press is \"Spc\"\n");
				break;
				case 13:
				printf(" you press is \"Enter\"\n");
				break;
				case 72:
				printf(" you press is \"¡ô\"\n");
				break;
				case 80:
				printf(" you press is \"¡õ\"\n");
				break;
				case 77:
				printf(" you press is \"¡÷\"\n");
				break;
				case 75:
				printf(" you press is \"¡ö\"\n");
				break;
				case 71:
				printf(" you press is \"Home\"\n");
				break;
				case 79:
				printf(" you press is \"End\"\n");
				break;
				case 73:
				printf(" you press is \"PgUp\"\n");
				break;
				case 81:
				printf(" you press is \"PgDn\"\n");
				break;
				case 82:
				printf(" you press is \"Ins\"\n");
				break;
				case 83:
				printf(" you press is \"Del\"\n");
				break;
			}
		}else{
			printf("\n");
			printf("ascii is %d\n",c1);
			printf("you press is %c\n",c1);
		}
	}
    system("PAUSE");
    return 0;
}
