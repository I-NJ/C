#include<stdio.h>
#include<Stdlib.h>

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
	
	system("cls");
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
	while(1)
	screen();
	
}
