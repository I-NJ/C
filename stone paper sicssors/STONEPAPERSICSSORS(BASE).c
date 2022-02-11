#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>

void delay(int t)
{
	int i,j;
	for(i=0;i<1000*t;i++)
	{
		for(j=0;j<32676;j++);
	}
}

int main()
{
	initGraphics();
	initGraphics(10,10);
	int u_choice=97,random,rand_num[3]={97,115,100},win=0,user_no;
	char name[3][10]={"ROCK","Paper","Scissors"};
	
	srand(time(0)); 
	printf("Stone for a\n");
	printf("Paper for s\n");
	printf("scissors for d\n");
	printf("Press anykey to start");
	getch();
	system("cls");
while(1){
	while(1){
	u_choice=getch();
	if(u_choice=='a')
	user_no=0;
	else if(u_choice=='s')
	user_no=1;
	else if(u_choice=='d')
	user_no=2;
	
	//a=97(rock) s=115(paper) d=100(scissors)
	random=(rand()%3+0);
	printf("\n%sX%s",name[user_no],name[random]);
	if(u_choice!=rand_num[random])
	{
		if(u_choice=97&&rand_num[random]==100)
		win=1;
		else if(u_choice=97&&rand_num[random]==115)
		win=0;
		else if(u_choice=115&&rand_num[random]==100)
		win=0;
		else if(u_choice=115&&rand_num[random]==97)
		win=1;
		else if(u_choice=100&&rand_num[random]==97)
		win=1;
		else if(u_choice=100&&rand_num[random]==115)
		win=0;
		
		break;
	}
	else if(u_choice==rand_num[random])
	printf("\nagain");
	}
	if(win==1)
	printf("\nYOU WON");
	else if(win==0)
	printf("\nCOMPUTER WON");
}
	return 0;
}


