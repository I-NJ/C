#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int size_y=11;
int size_x=21;
int map[100][100];

void delay(int a)
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<32400;j++);
	}
}

void print(int a,int b)
{
	
	int i,j;
	system("cls");
	for(i=0;i<size_y;i++)
	{
		for(j=0;j<size_x;j++)
		{
			if(i==a&&j==b)
			printf("%c",2);
			else if(map[i][j]==1)
			printf("%c",178);
			else
			printf("%c",32);
			
		}
		printf("\n");
	}
	printf("a=%d   b=%d",a,b);
}

int main()
{
	int a=5,b=10,pos,loop=0,l_a=0,l_b=0,l_pos=0;//l=last postions
	FILE* fp;
	fp=fopen("map4.txt","r");
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		fscanf(fp,"%d",&map[i][j]);
	}
	
	while(1)
	{
		delay(300);
		print(a,b);
		l_a=a;
		l_b=b;
		l_pos=pos;
		again:
		if(kbhit()!=0)
		pos=getch();
		if(pos=='d'&&b<(size_x-1))
		{
			b++;
			
		}
		else if(pos=='s'&&a<(size_y-1))
		{
			a++;
			
		}
		else if(pos=='w'&&a>0)
		{
			a--;
			
		}
		else if(pos=='a'&&b>0)
		{
			b--;
			
		}
		else
		pos=l_pos;
		
		if(map[a][b]==1)
		{
		a=l_a;
		b=l_b;
		pos=0;
		goto again;
		}
		}
}
