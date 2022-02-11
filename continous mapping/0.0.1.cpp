#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int size_x=50;
int size_y=7;

void delay(int a)
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<32678;j++);
	}
}

int print(int b,int a,int trail[7][50],int points)
{
	int i,j;
	delay(200);
	system("cls");
	for(i=0;i<size_y;i++)
	{
		for(j=0;j<size_x;j++)
		{
			if(i==a&&j==b)
			printf("%c",178);
			else if(i==0&j==0)
			printf("%c",201);
			else if(i==0&j==(size_x-1))
			printf("%c",187);			
			else if(i==(size_y-1)&j==0)
			printf("%c",200);
			else if(i==(size_y-1)&j==(size_x-1))
			printf("%c",188);
			else if(i==(size_y-1)||i==0)
			printf("%c",205);
			else if(j==0||j==(size_x-1))
			printf("%c",186);
			else if(trail[a][b]==1)
			{
				system("cls");
				printf("Game Over");
				printf("\nPoints=%d",points);
				getch();
			}
			else if(trail[a][b]==2)
			{
				points=points+1;
				trail[a][b]=0;
			
			}
			else if(trail[i][j]==1)
			printf("%c",219);
			else if(trail[i][j]==2)
			printf("F");
			else
			printf("%c",32);;
			
		}
		printf("\n");
	}
	printf("x=%d;y=%d,value=%d",b,a,trail[a][b]);
	
	return points;
}

int main()
{
	int trail[7][50],x=2,y=3,pos,block,no_of_loops=0,food,points=0;
	
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<49;j++)
		trail[i][j]=0;
	}
	
	trail[2][47]=1;
	while(1)
	{
	points=print(x,y,trail,points);
	if(kbhit()!=0)
	pos=getch();
	if(pos=='w'&&y>1)
	{
	y=y-1;
	pos=0;
	}
	else if(pos=='s'&&y<5)
	{
	y=y+1;
	pos=0;
	}
	else if(pos=='d'&&x<48)
	{
		x=x+1;
		pos=0;
	}
	else if(pos=='a'&&x>1)
	{
		x=x-1;
		pos=0;
	}
	
	if((no_of_loops%10)==0)
	{
	block=rand()%5+1;
	trail[block][47]=1;
	}
	if((no_of_loops%14)==0)
	{
		food=rand()%5+1;
		trail[food][47]=2;
	}
	
	for(int i=0;i<7;i++)
	{
		for(int j=1;j<49;j++)
		{
			trail[i][j-1]=trail[i][j];
			trail[i][j]=0;
		}
	}
	no_of_loops=no_of_loops+1;
	
	
	
	
	}
}
