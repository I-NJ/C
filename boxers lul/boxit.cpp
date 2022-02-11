#include<stdio.h>
#include<string.h>

void boxit()
{
	int c=10;
	int n_c=5;
	int n_r=10;
	for(int i=1;i<=n_r;i++)
	{
		for(int j=1;j<=c*n_c;j++)
		{
			if(j==1&&i==1)
				printf("%c",201);//top left
			else if(j==c*n_c&&i==1)
				printf("%c",187);//top right
			else if(j%c==0&&i==1)
				printf("%c",203);//column divison
			else if(i==3&&j==1)
				printf("%c",204);//header left corner
			else if(i==3&&j==c*n_c)
				printf("%c",185);// header right corner
			else if(i==3&&j%c==0)
				printf("%c",206);// header divider
			else if(i==n_r&&j==1)
				printf("%c",200);//bottom left
			else if(i==n_r&&j==c*n_c)
				printf("%c",188);//bottom right
			else if(i==n_r&&j%c==0)
				printf("%c",202);//bottom divider
			else if(j%c==0||j==1)
					printf("%c",186);//vertical line
			else if(i==1||i==n_r||i==3)
				printf("%c",205);//horizantal line
			else
				printf(" ");	
			
		}
		printf("\n");
	}
	
}

int main()
{
	boxit();
}
