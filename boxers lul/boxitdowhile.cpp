#include<stdio.h>
#include<string.h>

void boxit(char main[5][10],char car[5][9])
{
	printf("\n");
	int j=0,i=1,k=0,l=0,count=0;
	int c=10;//change the string print size
	int n_c=5;
	int n_r;//rows + 4
	printf("\n ENter number of cars : ");
	scanf("%d",&n_r);
	n_r=n_r+4;
	do
	{
		j=0;
		l=0;
		do
		{
			if(j==0&&i==1)
				printf("%c",201);//top left
			else if(j==c*n_c&&i==1)
				printf("%c",187);//top right
			else if(j%c==0&&i==1)
				printf("%c",203);//column divison
			else if(i==3&&j==0)
				printf("%c",204);//header left corner
			else if(i==3&&j==c*n_c)
				printf("%c",185);// header right corner
			else if(i==3&&j%c==0)
				printf("%c",206);// header divider
			else if(i==n_r&&j==0)
				printf("%c",200);//bottom left
			else if(i==n_r&&j==c*n_c)
				printf("%c",188);//bottom right
			else if(i==n_r&&j%c==0)
				printf("%c",202);//bottom divider
			else if(j%c==0||j==0)
				printf("%c",186);//vertical line
			else if(i==1||i==n_r||i==3)
				printf("%c",205);//horizantal line
			else if(((j-1)%c==0)||j>0)
				{//all the empty spaces
					if(i==2)
					{
					printf("%-9s",main[k]);
					k++;
					}
					else
					{
					if(l==0)
					printf("%-9d",(count/5)+1);
					else
					printf("%-9s",car[l]);
					l++;
					count++;
					}
					j=j+8;
				}
			else
				printf(" ");	
			
			j++;
		}while(j<=c*n_c);
		printf("\n");
		i++;
	}while(i<=n_r);
	
}

int main()
{
	char num='a';
	char main[5][10]={"SELECTION","CAR NAME","TIME IN ","TIME OUT","AMOUNT"};
	char car[5][9]={"1","KA01N096","12:00","8:00","Rs230"};
	boxit(main,car);
}
