#include <stdio.h>
#include <conio.h>
#include <string.h>


int calc(char name[15],int l_day,int l_month,int l_year,int b_day,int b_month)
{

	int allmonths[12],l_leap_year=0,years=0,months=0,days=0,b_leap_year=0;
	int b_year=0;
	char temp;
	
	char name_months[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	
	//printf("Today's Date(DD/MM/YYYY): ");
	//scanf("%d%c%d%c%d",&l_day,&temp,&l_month,&temp,&l_year);
	
	if(l_year%4==0)
	l_leap_year=1;
	else
	l_leap_year=0;
	allmonths[0]=31;//Jan
	if(l_leap_year=1)
	allmonths[1]=29;//Feb
	else
	allmonths[1]=28;
	allmonths[2]=31;//Mar
	allmonths[3]=30;//Apr
	allmonths[4]=31;//May
	allmonths[5]=30;//Jun
	allmonths[6]=31;//Jul
	allmonths[7]=31;//Aug
	allmonths[8]=30;//Sep
	allmonths[9]=31;//Oct
	allmonths[10]=30;//Nov
	allmonths[11]=31;//Dec
	
	
	if(b_month<l_month)
	b_year=l_year+1;
	else if(b_month>l_month)
	b_year=l_year;
	else if(b_month==l_month)
	{
		if(b_day<l_day)
		b_year=l_year+1;
		else
		b_year=l_year;
	}
	
	if(b_year%4==0)
	b_leap_year=1;
	else
	b_leap_year=0;
	
	if(b_leap_year=1)
	allmonths[1]=29;//Feb
	else
	allmonths[1]=28;
	
	
	years=b_year-l_year;
	months=b_month-l_month;
	days=b_day-l_day;
	
	if(days<0)
	{
		months=months-1;
		days=days+allmonths[l_month-1];
	}
	
	if(months<0)
	{
		years=years-1;
		months=months+12;
	}
	
	printf("%s's birthday is in %d months and %d days(%d %s)\n",name,months,days,b_day,name_months[b_month-1]);	
}

int main()
{
	int l_day,l_month,l_year,b_day,b_month;
	char name[20],garbage,last[]="last";
	FILE *fp;
	fp=fopen("people.txt","a+");
	
	printf("\nEnter Today's Date(DD/MM/YYYY): ");
	scanf("%d%c%d%c%d",&l_day,&garbage,&l_month,&garbage,&l_year);
	
	
	while(1)
	{
	fscanf(fp,"%s%d%d",name,&b_day,&b_month);
	if(strcmp(name,last)==0)
	break;
	else	
	calc(name,l_day,l_month,l_year,b_day,b_month);
	}
	
	
	
}
