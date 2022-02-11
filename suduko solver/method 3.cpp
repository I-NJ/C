#include<stdio.h>

int row_check(int s[9][9],int r,int num)
{
	for(int i=0;i<9;i++)
	{
		if(s[r][i]==num)
		return 0;
	}
	return 1;
}
int col_check(int s[9][9],int c,int num)
{
	for(int i=0;i<9;i++)
	{
		if(s[i][c]==num)
		return 0;
	}
	return 1;
}

int box_check(int s[9][9],int r,int c,int num)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		if(s[i+r-r%3][j+c-c%3]==num)
		return 0;
	}
	return 1;
}

int fillable(int s[9][9],int i,int j,int num)
{
	int r,c,b;
	r=row_check(s,i,num);
	c=col_check(s,j,num);
	b=box_check(s,i,j,num);
	
	if(r==1&&c==1&&b==1)
	return 1;
	else
	return 0;
	
}

int solve(int s[9][9],int fill[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(fill[i][j]!=1)
			{
				for(int n=1;n<10;n++)
				{
					if(fillable(s,i,j,n))
					s[i][j]=n;
					fill[i][j]=1;
				}
			}
		}
	}
	
	printf("\nAnswer\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		printf("%d ",s[i][j]);
		printf("\n");
	}
	
}


int main()
{
	int suduko[9][9],filled[9][9];
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		filled[i][j]=0;
	}
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
		scanf("%d",&suduko[i][j]);
		if(suduko[i][j]!=0)
		filled[i][j]=1;
		}
	}
	
	solve(suduko,filled);
}
