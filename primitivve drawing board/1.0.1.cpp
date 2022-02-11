#include<Stdio.h>
#include<Conio.h>
#include<stdlib.h>
#include<time.h>

int size_y=20;
int size_x=40;
 
int main();
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{for(j=0;j<32767;j++);
	}
}

void printmenu()
{
	printf("\tCLEAN SLATE\n");
	printf("c-clear screen f-to draw pixel\n");
}

void print(int a,int b,int trail[100][100])
{
	int i,j;
	system("cls");
	printmenu();
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
			else if(trail[i][j]==1)
			printf("%c",219);
			else
			printf("%c",32);
			
		}
		printf("\n");
	}
	printf("a=%d;b=%d,value=%d",a,b,trail[a][b]);
}

int main()
{
	int a=1,b=1,pos,trail[100][100];
	for(int i=0;i<size_y;i++)
	{
		for(int j=0;j<size_x;j++)
		trail[i][j]=0;
	}

	
while(1)
	{
	
		print(a,b,trail);
		delay(250);
		
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
		else if(pos=='f')
		trail[a][b]=1;
		else if(pos=='c')
		{
		for(int i=0;i<size_y;i++)
		{
		for(int j=0;j<size_x;j++)
		trail[i][j]=0;
		}
		}
		
		else if(pos==27)
		break;
		
	}
}
