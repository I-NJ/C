#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>
#include<conio.h>
int main()
{
	
	srand(time(0));
	int i=0,k=0;
	char a[20]={'H','A','P','P','Y',' ','N','E','W',' ','Y','E','A','R'};
	char b[30]={'C','H','E','R','I','S','H',' ','B','E','F','O','R','E',' ','Y','O','U',' ','P','E','R','I','S','H'};
	printf("\n\n\n\n\n\t\t\t\t");
	while(a[k]!='\0')
	{
	i=rand()%121+31;
	printf("%c",i,i);
	if(a[k]!=i)
	{
		if(a[k]==' ')
		{
		printf("\b");
		printf(" ");
		k++;
		}
		else
		printf("\b");
	}
	else 
	k++;
	usleep(10000);
	}
	printf("\n\t\t\t\t");
	k=0;
	while(b[k]!='\0')
	{
	i=rand()%121+31;
	printf("%c",i,i);
	if(b[k]!=i)
	{
		if(b[k]==' ')
		{
		printf("\b");
		printf(" ");
		k++;
		}
		else
		printf("\b");
	}
	else 
	k++;
	usleep(10000);
	}
	getch();
	getch();
}
