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

int printmenu(char heading[40],char contents[5][10],int size2d)
{
	int cursor=1,cursor_input=0;
	
	while(1){
	draw_line(25,178);
	printf("%-35s",heading);
	draw_line(25,178);
	printf("\n\n\n");
	for(int i=0;i<size2d;i++){
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
	
	cursor_input=getch();
	if(cursor_input==13)
	return cursor;
	else if(cursor_input==72&&cursor>1)
	cursor--;
	else if(cursor_input==80&&cursor<size2d)
	cursor++;
	system("cls");
	}
	
	
}

int main()
{
	char a[40] = {"New Horizon College of Enginnering"},b[5][10]={"CSE","ISE","ECE","EEE","CIV"};
	int c=5; 
	printmenu(a,b,c);
	
}
