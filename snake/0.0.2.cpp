//from primitive drawing boad
#include<Stdio.h>
#include<Conio.h>
#include<stdlib.h>
#include<time.h>

int size_y=10;
int size_x=40;

int play_area[100][100];
int s_x[400];
int s_y[400];
int score=1;
int f_x;
int f_y;
int l_pos;

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
		
		if(i==1)
		{
			s_x[i]=s_x[i-1];
			s_y[i]=s_y[i-1];
			s_x[i-1]=a;
			s_y[i-1]=b;
			play_area[s_x[i-1]][s_y[i-1]]=1;
		}
		s_x[i]=s_x[i-1];
		s_y[i]=s_y[i-1];
		play_area[s_x[i]][s_y[i]]=1;	
	}
}

void food()
{
	f_x=rand()%7+2;
	f_y=rand()%37+2;
	if(play_area[f_x][f_y]==1)
	food();
	else
	play_area[f_x][f_y]=2;
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
			else if(play_area[i][j]==1)
			printf("%c",15);
			else if(play_area[i][j]==2)
			printf("%c",3);
			else
			printf("%c",32);
			
		}
		printf("\n");
	}
	printf("a=%d;b=%d,value=%d,food=(%d,%d),score=%d,playarea=%d,l_pos=%c",a,b,score,f_x,f_y,score,play_area[i][j],l_pos);

}

int main()
{
	int a=1,b=1,pos,f_present=0;
	srand(time(0));
	
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		play_area[i][j]=0;
	}
	for(int i=0;i<400;i++)
	{
		s_x[i]=0;
		s_y[i]=0;
	}

	
while(1)
	{
		
		delay();
		again:
		grow(a,b);
		if(f_present==0)
		{
		food();
		f_present=1;
		}
		else if(a==f_x&&b==f_y)
		{
			score++;
			f_present=0;
		
		}
		l_pos=pos;
		print(a,b);
		if(kbhit()!=0)
		pos=getch();
		if(l_pos=='a'&&pos=='d')
		{
			pos='a';
		}
		else if(l_pos=='d'&&pos=='a')
		{
			pos='d';
		}
		else if(l_pos=='w'&&pos=='s')
		{
			pos='w';
		}	
		else if(l_pos=='s'&&pos=='w')
		{
			pos='s';
		}
		if(pos=='d'&b<(size_x-1))
		{
			b++;
			if(play_area[a][b]==1)
			break;
			else if(b==size_x-1)
			b=1;
			
		}
		else if(pos=='s'&a<(size_y-1))
		{
			a++;
			if(play_area[a][b]==1)
			break;
			else if(a==size_y-1)
			a=1;
			
		}
		else if(pos=='w'&a>0)
		{
			a--;
			if(play_area[a][b]==1)
			break;
			else if(a==0)
			a=size_y-2;
			
		}
		else if(pos=='a'&b>0)
		{
			b--;
			if(play_area[a][b]==1)
			break;
			else if(b==0)
			b=size_x-2;
			
		}
		else if(pos==27)
		break;
		else
		continue;
		}
	}

