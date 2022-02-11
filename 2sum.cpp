#include<stdio.h>

int main()
{
	int i,j,sum2=11,num[10];
	for(int i=0;i<10;i++)
	num[i]=i;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		if((num[i]+num[j])==sum2)
		{
			printf("%d+%d=%d\n",num[i],num[j],sum2);
			break;
		}
		else
		continue;
	}
	
	
	
}
