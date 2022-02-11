#include<Stdio.h>
#include<Conio.h>
#include<stdlib.h>
#include<time.h>
int main();
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{for(j=0;j<32767;j++);}	
}
void print(int a,int b,int win_a,int win_b,int e_posx,int e_posy)
{
	int i,j;
	system("cls");
	for(i=0;i<11;i++)
	{
		for(j=0;j<21;j++)
		{
			if(i==a&&j==b)
			printf("%c",2);
			else if(j==e_posy&&i==e_posx)
			printf("%c",1);
			else if(i==win_a&&j==win_b)
			printf("%c",4);
			else if(i==0&j==0)
			printf("%c",201);
			else if(i==0&j==20)
			printf("%c",187);			
			else if(i==10&j==0)
			printf("%c",200);
			else if(i==10&j==20)
			printf("%c",188);
			else if(i==10||i==0)
			printf("%c",205);
			else if(j==0||j==20)
			printf("%c",186);
			else
			printf("%c",32);
			
			
			
		}
		printf("\n");
	}
}

int main()
{
	
	int i,j,a=1,b=1,win=1,win_a=1,win_b=1,point=-1,move=0,e_posx=9,e_posy=9,difficulty,speed=0;
	char pos,end;
	
	system("cls");
	srand(time(0));
	printf("\t\tWelcome to THE GAME");
	printf("\n\nuse a,s,d,f to control the character(%c)",2);
	printf("\nEscape from Mr.Danger(%c) and collect points(%c)",1,3);
	printf("\nClick Esc to exit at any point of time");
	printf("\nDifficulty:");
	printf("\n1.Easy");
	printf("\n2.Medium");
	printf("\n3.Hard");
	printf("\n4.Gamer Hard");
	printf("\n5.IT is a nightmare\n");
	printf("Enter the number beside your choice and press enter:");
	scanf("%d",&difficulty);
	if(difficulty==1)
	speed=10;
	if(difficulty==2)
	speed=8;
	if(difficulty==3)
	speed=6;
	if(difficulty==4)
	speed=3;
	if(difficulty==5)
	speed=1;	
	printf("\nPress any key to continue");
	getch();
	
	again:
	a=1;
	b=1;
	win=1;
	win_a=1;
	win_b=1;
	point=-1;
	move=0;
	e_posx=9;
	e_posy=9;
	pos=0;
	while(win)
	{
		if(a==win_a&&b==win_b)
		{
			win_a=(rand()%9+1);
			win_b=(rand()%19+1);
			point++;
		}
		print(a,b,win_a,win_b,e_posx,e_posy);
		delay(1000);
		if(kbhit()!=0)
		pos=getch();
		move++;
		if(pos=='d'&&b<19)
		{
			b++;
		}
		else if(pos=='s'&&a<9)
		{
			a++;
		}
		else if(pos=='w'&&a>1)
		{
			a--;
		}
		else if(pos=='a'&&b>1)
		{
			b--;
		}
		else if(pos==27)
		break;
		if(move%speed==0)
		{
		if(a<e_posx)
		e_posx--;
		else if(a>e_posx)
		e_posx++;
		else if(b<e_posy)
		e_posy--;
		else if(b>e_posy)
		e_posy++;
		move=0;
		}
		if(a==e_posx&&b==e_posy)
		break;
		
	}
	system("cls");
	printf("Game over");
	delay(10000);
	printf("\nPress any key");
	getch();
	system("cls");
	printf("\nYou have scored %d",point);
	printf("\nPress Esc key to exit");
	printf("\nPress any other key to play again");
	if(getch()!=27)
	goto again;
}




