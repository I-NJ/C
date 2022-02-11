#include<stdio.h>
#include<conio.h>

void print(int a,int b)
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<21;j++)
		{
			if(i==a&&j==b)
			printf("%c",178);
			else
			printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	int a,b;
	a=5;
	b=11;
	print(a,b);
	
	
}
