#include<stdio.h>

int check(int s[9][9])
{
	int key,found=0,a[9],i,j,c=0,r=0;
	
	while(1)
	{
		key=s[c][r];
		if(key==0)
		{
			found=1;
		}
		for(i=0;i<9;i++)
		{
			if(s[i][r]==key)
			{
				if(i!=c)
				{
				found=1;
				break;
				}
			}	
		}
		for(j=0;j<9;j++)
		{
			if(s[c][j]==key)
			{
				if(j!=r)
				{
				found=1;
				break;
				}
			}
		}
		r=r+1;
		if(r>8)
		{
			c++;
			r=0;
		}
		if(c>8)
		{
			break;
		}

	}
		
	
	return found;
}


int main()
{
	int suduko[9][9],found;
	
	
	printf("Enter the suduko:\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		scanf("%d",&suduko[i][j]);
	}
	
	found=check(suduko);
	
	if(found==1)
	printf("\nSuduko is Not GOOD",found);
	else 
	printf("\nSuduko is good",found);
	
	
	
	
	
	
}
