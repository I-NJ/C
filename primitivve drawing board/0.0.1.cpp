#include<Stdio.h>
#include<Conio.h>
#include<stdlib.h>
#include<time.h>
int main();
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{for(j=0;j<32767;j++);
	}
}

void print(int a,int b,int trail[11][11])
{
	int i,j;
	system("cls");
	for(i=0;i<11;i++)
	{
		for(j=0;j<11;j++)
		{
			if(i==a&&j==b)
			printf("%c",178);
			else if(i==0&j==0)
			printf("%c",201);
			else if(i==0&j==10)
			printf("%c",187);			
			else if(i==10&j==0)
			printf("%c",200);
			else if(i==10&j==10)
			printf("%c",188);
			else if(i==10||i==0)
			printf("%c",205);
			else if(j==0||j==10)
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
	int a=1,b=1,pos,trail[11][11];
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		trail[i][j]=0;
	}
	
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		printf("%d",trail[i][j]);
	}
	
while(1)
	{
	
		print(a,b,trail);
		delay(1000);
		//if(kbhit()!=0)
		pos=getch();
		if(pos=='d'&&b<9)
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
		else if(pos=='f')
		trail[a][b]=1;
		else if(pos==27)
		break;
		
	}
}
