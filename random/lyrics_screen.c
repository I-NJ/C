#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<WinCon.h>



void delay(int a)
{
	for(int i=0;i<a;i++)
	for(int j=0;j<32000;j++);
	
}


void screen()
{
	FILE *fp;
	char l;
	fp=fopen("lyrics.txt","r");
	
	while(1)
	{
		fscanf(fp,"%c",&l);
		printf("%c",l);
		delay(2000);
		
		if(feof(fp))
		break;
	}
}



int main()
{
	WINAPI GetConsoleWindow(void);
	screen();
	
}
