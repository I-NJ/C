#include <stdio.h>
#include <time.h>
int main(void)
{
	struct tm* ptr;
    time_t t;
    int time1,time2,loop=0;
    getch();
	while(1){
	time2=time1;
    t = time(NULL);
    ptr = localtime(&t);
    time1=(*ptr).tm_sec;
    if(time1>time2)
    {
	printf("%s", asctime(ptr));
    printf("%d\n",(*ptr).tm_sec);
    loop++;
    }
    if(loop>10)
    break;
    }
    
}
