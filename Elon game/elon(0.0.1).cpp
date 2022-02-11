#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

void delay(int a){int i,j;for(i=0;i<a;i++){for(j=0;j<32767;j++);}}

void print(int a,int b,int draw[11][21],int direction_x,int direction_y,int e_posx,int e_posy)
{
	int i,j;
	system("cls");
	for(i=0;i<11;i++)
	{
		for(j=0;j<21;j++)
		{
			if(i==a&&j==b)
			printf("%c",2);
			else if(i==0&j==0)
			printf("%c",201);
			else if(i==0&j==20)
			printf("%c",187);			
			else if(i==10&j==0)
			printf("%c",200);
			else if(i==10&j==20)
			printf("%c",188);
			else if(i==10||i==0)
			printf("%c",205);
			else if(j==0||j==20)
			printf("%c",186);
			else if(draw[i][j]==1)
			printf("%c",24);
			else if(draw[i][j]==2)
			printf("%c",12);
			else
			printf("%c",32);
			
			
			
		}
		printf("\n");
	}
	printf("a=%d, b=%d, f_x=%d, f_y=%d, e_x=%d, e_y=%d",a,b,direction_x,direction_y,e_posx,e_posy);
}


int main()
{
	int a=9,b=10,pos,draw[11][21],direction_x=0,direction_y=0,e_posx=0,e_posy=0,points=0,hearts=5,fuel=100,loop=0,last_pos=0;
	
	srand(time(0));
	
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<49;j++)
		draw[i][j]=0;
	}
	while(1)
	{
	loop=loop+1;
	delay(200);
	
	print(a,b,draw,direction_x,direction_y,e_posx,e_posy);
	printf("\npoints=%d,hearts=%d,fuel=%d",points,hearts,fuel);

		if(e_posx==0||e_posy==0)
		{
		e_posy=rand()%7+2;
		e_posx=rand()%19+1;
		draw[e_posy][e_posx]=2;
		}
		
	
		last_pos=pos;
		if(kbhit()!=0)
		pos=getch();
		
		if(pos=='d'&&b<19)
		{
			b++;
		}
		else if(pos=='s'&&a<9)
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
		else if(pos==32&&direction_y==0)
		{
			direction_x=b;
			direction_y=a;
			pos=last_pos;
			fuel=fuel-1;
		}
		
		
		
		if(direction_y!=0)
		{
			direction_y=direction_y-1;
			draw[direction_y][direction_x]=1;
			if((direction_y+1)!=a)
			{
				draw[direction_y+1][direction_x]=0;
			}
		}
		
		if(direction_x==e_posx&&direction_y==e_posy)
		{
			e_posx=0;
			e_posy=0;
			points=points+1;
		}
		
		if(e_posx==b&&e_posy==a)
		{
			hearts=hearts-1;
			draw[e_posy][e_posx]=0;
			e_posx=0;
			e_posy=0;
			if(hearts==0)
			break;
		}
		
		if(loop%10==0)
		{
		e_posx=e_posx-1;
		draw[e_posy][e_posx]=2;
		draw[e_posy][e_posx+1]=0;
		if(e_posx<1)
		{
			e_posx=20;
		}
		}
		
		if(b==1)
		{
			b=18;
		}
		if(b==19)
		{
			b=2;
		}
			
		if(fuel==0)
		{
			printf("\nOut of Fuel");
			break;
		}
		}
}
