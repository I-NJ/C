#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void draw_line(int lenth,int type_char)
{
	printf(" ");
	for(int i=0;i<lenth;i++)
	printf("%c",type_char);
	printf(" ");	
}

int printmenu(char heading[40],char contents[10][10],int size2d)
{
	int cursor=1,cursor_input=0,length=0,start;
	if(size2d<5)
	length=size2d-5;
	
	if(length<0)
	start=0;
	else
	start=length;
	
	while(1){
	draw_line(25,178);
	printf("%-35s",heading);
	draw_line(25,178);
	printf("\n\t\t\t\t\t\t\t\tNumber of Contents= %02d ",size2d);
	printf("\n\n");
	for(int i=start;i<(length+5);i++){
	draw_line(25,177);
	if(i+1==cursor)
	printf("%c ",16);
	else
	printf("  ");
	printf("%d. %-30s",i+1,contents[i]);
	draw_line(25,177);
	printf("\n\n");
	}
	printf("Use Arrow Key to control your choice '%c' use up and down arrow and press enter",16);
	
	cursor_input=getch();
	if(cursor_input==13)
	return cursor;
	else if(cursor_input==72&&cursor>1)
	cursor--;
	else if(cursor_input==80&&cursor<size2d)
	cursor++;
	if(cursor>length+5)
	length++;
	else if(cursor<length+5&&length>0&&(cursor-length)==0)
	length--;
	system("cls");
	}
	
	
}

int main()
{
	int two_d[2][5],i,out,j;
	long long int sum=0,product=0;
	char selection[10][10]={"ADD","MULTIPLY"},heading[10]="OPTIONS";
	
	printf("Enter 10 number :");
	for(i=0;i<2;i++)
	{
		for(j=0;j<5;j++)
		scanf("%d",&two_d[i][j]);
	}
	system("cls");
	out=printmenu(heading,selection,2);
	system("cls");
	
	if(out==1)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<5;j++)
			sum=sum+two_d[i][j];
		}
		printf("Sum of all elements in the given One-D array is %ld",sum);
	}
	else if(out==2)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<5;j++)
			product=product*two_d[i][j];
		}
		printf("Product of All elements in the given One-D array is %ld",product);
	}
}
