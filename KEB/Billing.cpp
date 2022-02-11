#include <stdio.h>
#include <conio.h>

void line()
{
	printf("\n");
	for(int i=0;i<18;i++)
	printf("- ");
}

int bill()//char RR_no[7]
{
	char info_char[10][23];/*
	info_char[0]==RR no
	info_char[1]==Acc id
	info_char[2]==MR code
	info_char[3]==name
	info_char[4]==area name
	info_char[5]==city
	info_char[6]==Tariff
	info_char[7]==Sanc load
	info_char[8]==date range
	info_char[9]==date of reading
	info_char[10]==billno
	*/
	FILE *fp;
	fp=fopen("KL58887.txt","r");
	for(int i=0;i<11;i++)
	fscanf(fp,"%s",info_char[i]);
	
	printf("\nAccount details");
	printf("\nRR NO:        %20s",info_char[0]);
	printf("\nAccount ID:   %20s",info_char[1]);
	printf("\nMR Code:      %20s",info_char[2]);
	line();
	printf("\nPersonal Details");
	printf("\nName and Address");
	printf("\n%s %s %s",info_char[3],info_char[4],info_char[5]);
	line();
	printf("\nConnection Details");
	printf("\nTariff:       %20s",info_char[6]);
	printf("\nSanc Load:    %20s",info_char[7]);
	line();
	printf("\nBilling Details");
	printf("\nBill period  %20s",info_char[8]);
	printf("\nRdng Date:    %20s",info_char[9]);
	printf("\nBill no:      %20s",info_char[10]);
	line();
	
	

}

int main()
{
	bill();
}
