#include<stdio.h>

int main()
{
	char s[100];
	scanf("%[^\n]s%*c",&s);
	printf("\n%s",s);
}

