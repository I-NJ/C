#include <stdio.h>

double test()
{
	int out;
	double bal;
	scanf("%d %lf",&out,&bal);
	if(out%5!=0||out>bal)
	return bal;
	else 
	return bal-out-0.50;
	
}

int main(void) {
	
	double score;
	score=test();
	printf("%.2f",score);
	return 0;
}
