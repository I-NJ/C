#include<stdio.h>

int check(int s[9][9],int i,int j)
{
	int a[11];
	for(int m=0;m<2;m++)
	{
	for(int k=0;k<9;k++)
	{
		for(int l=0;l<9;l++)
		{
			if(m==0)
			{
			if(s[i][k]==l+1)
			a[l]=1;
			}
			
			if(m==1)
			{
			if(s[k][j]==l+1)
			a[l]=1;	
			}
		}
	}
	}
	for(int n=0;n<9;n++)
	{
		if(a[n]!=1)
		return n;
		
	}
	
	
}


int main()
{
	int suduko[9][9],sol=0;
	
	printf("Enter the suduko:\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		scanf("%d",&suduko[i][j]);
	}

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(suduko[i][j]==0)
			{
				sol=check(suduko,i,j);
				suduko[i][j]=sol+1;
				printf("Sol=%d",sol);
			}
				
		}
	}
	
	printf("\nAnswer\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		printf("%d ",suduko[i][j]);
		printf("\n");
	}
}
