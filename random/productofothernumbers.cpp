#include<stdio.h>//product of all other number except that one

int main()
{
	int a[10],i,j,no,product[10];
	
	
	
	
	scanf("%d",&no);
	for(i=0;i<no;i++)
	product[i]=1;
	for(i=0;i<no;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<no;i++)
	{
		for(j=0;j<no;j++)
		{
			if(i!=j)
			product[i]=product[i]*(a[j]);
		}
	}
	
	for(i=0;i<no;i++)
	printf("%d ",product[i]);
	
	
	
}
