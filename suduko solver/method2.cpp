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

int solve(int s[9][9],int c,int r)
{
	int ans[15],non_zero=0,non_zero_element,a,b; //a and b are cube dimensions
	
	for(int i=0;i<9;i++)
	ans[i]=0;
	
	for(int i=0;i<2;i++)//to check both rows and columns
	{
		for(int j=0;j<9;j++)//to check all elements for that rows
		{
			for(int k=0;k<9;k++)//to check for every number form 1 to 9
			{
				if(i==0)
				{
					if(s[c][j]==k+1)
					ans[k]=1;
				}
				else if(i==1)
				{
					if(s[j][r]==k+1)
					ans[k]=1;	
				}	
			}
		}
	}
	//for checking respective cubes
	if(r<3&&c<3)
	{
	a=0;
	b=0;
	}
	if(r<3&&(c>2&&c<6))
	{
	a=3;
	b=0;	
	}
	if(r<3&&(c>5&&c<9))
	{
	a=6;
	b=0;
	}
	if((r>2&&r<6)&&c<3)
	{
	a=0;
	b=3;
	}
	if((r>2&&r<6)&&(c>2&&c<6))
	{
	a=3;
	b=3;
	}
	if((r>2&&r<6)&&c>5)
	{
	a=6;//c
	b=3;//r
	}
	if(r>5&&c<3)
	{
	a=0;//c
	b=6;//r
	}
	if(r>5&&(c>2&&c<6))
	{
	a=3;//c
	b=6;//r
	}
	if(r>5&&c>5)
	{
	a=6;
	b=6;
	}
	for(int i=a;i<a+3;i++)
	{
		for(int j=b;j<b+3;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	
	
	for(int i=0;i<9;i++)
	{
		if(ans[i]!=1)
		{
		non_zero=non_zero+1;
		non_zero_element=i+1;
		printf("\nanswer :%d,row=%d,column=%d\n",i+1,c+1,r+1);
		}
	}
	
	for(int i=0;i<9;i++)
	printf("%d\t",ans[i]);
	printf("\n");
	
	
	if(non_zero==1)
	return non_zero_element;
	else
	return 0;
	
}


int suduko_solve(int suduko[9][9])
{
	int sol=0,result=0,zero_elements=0;
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(suduko[i][j]==0)
			{
				sol=solve(suduko,i,j);
				if(sol!=0)
				suduko[i][j]=sol;
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
		if(suduko[i][j]==0)
		zero_elements=zero_elements+1;
		printf("%d ",suduko[i][j]);
		}
		printf("\n");
	}
	printf("\nTotal number of zero elements=%d\n",zero_elements);
	
	result=check(suduko);
	if(result!=1)
	{
	printf("\nDone!");
	printf("\nTotal number of zero elements=%d\n",zero_elements);
	}
	else
	suduko_solve(suduko);
	
}


int main()
{
	int suduko[9][9],sol=0,result=0;
	
	printf("Enter the suduko:\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		scanf("%d",&suduko[i][j]);
	}
	suduko_solve(suduko);
}

