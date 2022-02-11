#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int a,j;
    char s1[30];
        scanf("%d%lf",&i,&d);
        gets(s1);
        printf("%.0lf",i+d);
        printf("\n%.1lf",i-d);
        printf("\n%s",s);
        printf("%s",s1);
        
    return 0;
}
