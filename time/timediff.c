#include<stdio.h>
#include <time.h>

int time_diff(int hr_in ,int min_in,int sec_in,int hr_out ,int min_out ,int sec_out )
{
	long long int sec=0;
	int min=0,hr=0;
	
	sec =(( hr_out*60*60 + min_out*60 + sec_out )-( hr_in*60*60 + min_in*60 + sec_in ));
	
	min=sec/60;
	hr=min/60;
	min=min%60;
	sec=sec%60;
	
	printf("\nTotal time car stayed is hr : %d || min : %d  || sec : %d ",hr,min,sec);
}

int main()
{
	int hr_in,min_in,sec_in,hr_out,min_out,sec_out; 
	struct tm* ptr;
    time_t t;
    
    t = time(NULL);
    ptr = localtime(&t);
    
	printf("\nPress any key to checkin a vehicle >>>");
    getch();
    
    t = time(NULL);
    ptr = localtime(&t);
	printf("\n\nVehicle checked in at %s",asctime(ptr));
	hr_in = (*ptr).tm_hour;
	min_in = (*ptr).tm_min;
	sec_in = (*ptr).tm_sec;
	printf("\nPress any key to check out the vehicle >>>");
	getch();
	t = time(NULL);
    ptr = localtime(&t);
	printf("\n\nVehicke checked out at %s",asctime(ptr));
	hr_out = (*ptr).tm_hour;
	min_out = (*ptr).tm_min;
	sec_out = (*ptr).tm_sec;
	
	time_diff(hr_in,min_in,sec_in,hr_out,min_out,sec_out);
	return 0;
}
