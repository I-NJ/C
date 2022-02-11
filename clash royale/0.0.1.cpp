#include <stdio.h>
#include <time.h>
#include <conio.h>
/*struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  };*/

int var=1;

void print_bar(int len,int player)
{
	printf("%d\t");
	for(int i=0;i<len;i++)
	printf("%c ",178);
	printf("\n");
}

int main(void)
{
	struct tm* ptr;
    time_t t;
    int time1,time2=0,score=0,input=0,loop=0;
	
	
	while(1){
	loop++;
	time2=time1;
    t = time(NULL);
    ptr = localtime(&t);
    time1=(*ptr).tm_sec;
    if(time1>time2)
    {
    if(kbhit()!=0)
	input=getch();
	else if(kbhit()==0)
	input=0;
    if(score<10)
    {
	score++;
	if(input=='a'&&((score-var)>=0))
	{
	var=4;
	score=score-var;
	}
	else if(input=='s'&&((score-var)>=0))
	{
	var=3;
	score=score-var;
	}
	
	print_bar(score,2);
	}
	
	}
	}
}
