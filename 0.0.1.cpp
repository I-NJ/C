#include<Stdio.h>
#include<Conio.h>
#include<stdlib.h>
#include<time.h>

int size_y=10;
int size_x=20;
int main();

void save(int a[100][100])
{
	char file_name[20];
	FILE *fp1,*fp2;
	
	system("cls");	
	scanf("%s",file_name);
	fp1=fopen(file_name,"w");
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		fprintf(fp1,"%d\t",a[i][j]);
	}
	fprintf(fp1,"%d",420);
	fclose(fp1);
	fp2=fopen("save.nir","a+");
	fprintf(fp2,"%s\n",file_name);
	fclose(fp2);
	
}

void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{for(j=0;j<32767;j++);
	}	
}

void printmenu()
{
	printf("\tNote Pad\n");

}

void print(int a,int b,int trail[100][100],int draw)
{
	int i,j;
	system("cls");
	printmenu();
	for(i=0;i<size_y;i++)
	{
		for(j=0;j<size_x;j++)
		{
			if(i==a&&j==b)
			printf("%c",178);
			else if(i==0&j==0)
			printf("%c",201);
			else if(i==0&j==(size_x-1))
			printf("%c",187);			
			else if(i==(size_y-1)&j==0)
			printf("%c",200);
			else if(i==(size_y-1)&j==(size_x-1))
			printf("%c",188);
			else if(i==(size_y-1)||i==0)
			printf("%c",205);
			else if(j==0||j==(size_x-1))
			printf("%c",186);
			else if(trail[i][j]!=0)
			printf("%c",trail[i][j]);
			else
			printf("%c",32);
			
		}
		printf("\n");
	}
	printf("a=%d;b=%d",a,b,trail[a][b]);
	if(draw==1)
	printf("\nContinious Draw Mode");
	else if(draw==2)
	printf("\nErase mode ");
	else if(draw==0)
	printf("\nNormal Mode");

}

int main()
{
	int a=1,b=1,pos,trail[100][100],file_no,draw=0;
	FILE *fp1,*fp2;
	char file_name[10][20];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		trail[i][j]=0;
	}

	
while(1)
	{
	
		print(a,b,trail,draw);
		
		pos=getch();
		if(pos==8)
		{
			if(b==1)
			{
				if((a-1)!=0)
				{
				--a;
				b=size_x-2;
				}
			}
			else
			b--;
			trail[a][b]=0;
		}
		else if(pos=='*')//clear screen
		{
			for(int i=0;i<size_y;i++)
			{
				for(int j=0;j<size_x;j++)
				trail[i][j]=0;
			}
			a=1;
			b=1;
		}
		else if(pos=='/')//saving files
		save(trail);
		else if(pos=='-')//opening saved files
		{
			system("cls");
			fp2=fopen("save.nir","r");
			for(int i=0;i<20;i++)
			{
				fscanf(fp2,"%s",file_name[i]);
				printf("%d:%s\n",i+1,file_name[i]);
			}
			printf("Enter the file number you want to open : ");
			scanf("%d",&file_no);
			fp1=fopen(file_name[file_no-1],"r");
			for(int i=0;i<100;i++)
			{
				for(int j=0;j<100;j++)
				{
					fscanf(fp1,"%d",&trail[i][j]);
				}
			}
			fclose(fp1);
			fclose(fp2);
		}
		else if(pos==27)
		break;
		else
		{
		trail[a][b]=pos;
		b++;
		if(b>size_x-2)
		{
		a++;
		b=1;
		}
		}
	}
}
