#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void delay(int a)
{
	for(int i=0;i<a*100;i++)
	for(int j=0;j<32000;j++);
}


int main()
{
	char name[20],message[100],buff,l_buff;
	int ibuff;
	FILE *fp;
	fp=fopen("Messager.txt","a+");
	printf("Enter your name :");
	scanf("%s",name);
	while(1)
	{
		if(kbhit==0)
		{
		printf("\n%s:",name);
		scanf("%s",message);
		fprintf(fp,"%s:%s\n",name,message);
		fclose(fp);
		}
		system("cls");
		fp=fopen("Messager.txt","a+");
		while(ibuff=~getc(fp))
		putch(~ibuff);
	}
	

	
}
