//from primitive drawing boad
#include<Stdio.h>
#include<Conio.h>
#include<stdlib.h>
#include<time.h>

int size_y=10;
int size_x=20;

int play_area[100][100];
int s_x[200];
int s_y[200];
int score=10;

void delay()
{
	for(int i=0;i<1000;i++)
	for(int j=0;j<32000;j++);
}

void grow(int a,int b)
{
	play_area[s_x[score+1]][s_y[score+1]]=0;
	for(int i=score+1;i>0;i--)
	{
		s_x[i]=s_x[i-1];
		s_y[i]=s_y[i-1];
		play_area[s_x[i]][s_y[i]]=1;	
	}
	s_x[0]=a;
	s_y[0]=b;
	//play_area[s_x[0]][s_y[0]]=1;
}

void print(int a,int b)
{
	int i,j;
	system("cls");
	
	for(i=0;i<size_y;i++)
	{
		for(j=0;j<size_x;j++)
		{
			if(i==0&j==0)
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
			else if(play_area[i][j]==1)
			printf("%c",15);
			else
			printf("%c",32);
			
		}
		printf("\n");
	}
	printf("a=%d;b=%d,value=%d",a,b,score);

}

int main()
{
	int a=1,b=1,pos;
	srand(time(0));
	
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		play_area[i][j]=0;
	}
	for(int i=0;i<200;i++)
	{
		s_x[i]=0;
		s_y[i]=0;
	}
	
while(1)
	{
		delay();
		grow(a,b);
		print(a,b);
		if(kbhit()!=0)
		pos=getch();
		if(pos=='d'&&b<(size_x-2))
		{
			b++;
			
		}
		else if(pos=='s'&&a<(size_y-2))
		{
			a++;
			
		}
		else if(pos=='w'&&a>1)
		{
			a--;
			
		}
		else if(pos=='a'&&b>1)
		{
			b--;
			
		}
		else if(pos==27)
		break;
		}
		
		
	}

