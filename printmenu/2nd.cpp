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
	
	while(1){
		
		if(size2d<5)
			length=size2d-5;
	
		if(length<0)
			start=0;
		else
			start=length;
		
		draw_line(25,178);
		printf("%35s",heading);
		draw_line(25,178);
		printf("\n\t\t\t\t\t\t\t\tNumber of Contents= %02d ",size2d);
		printf("\n\n");
		for(int i=start;i<(length+5);i++)
		{
			draw_line(25,177);
			if(i+1==cursor)
				printf("%c ",16);
			else
				printf("  ");
			
			printf("%d. %-30s",i+1,contents[i]);
			draw_line(25,177);
			printf("\n\n");
		}
		printf("Use Arrow Key to control your choice '%c' use up and down arrow",16);
		printf("\nlength=%d,cursor=%d",length,cursor);
	
		cursor_input=getch();
		if(cursor_input==13)
			return cursor-1;
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
	char a[40] = {"New Horizon College of Enginnering"},b[10][10]={"CSE","ISE","i","o","p","l","n","niru","poppy"};
	int c=9,out; 
	out=printmenu(a,b,c);
	system("cls");
	printf("Choice= %s",b[out]);
	
}
