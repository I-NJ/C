#include<Stdio.h>
#include<Stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>

int main()
{
	int u_otp,otp;
	char num[4];
	srand(time(0));
	Again:
	otp=rand()%(9999-1001+1)+1001;
	printf("OTP recived in SMS = %d\n",otp);
	printf("Enter OTP :");
	for(int i=0;i<4;i++)
	{
	num[i]=getch();
	printf("*");
	}
	sscanf(num,"%d",&u_otp);
	if(otp==u_otp)
	printf("\nOTP is right and Account verified");
	else
	{
	printf("\nOTP is wrong Try again");
	sleep(1);
	system("cls");
	goto Again;
	}
}
