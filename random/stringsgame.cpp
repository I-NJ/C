#include <stdio.h> // header file for Standard Input Output
#include <stdlib.h> // header file for Standard Library

int gcd(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    if (a == b)
        return a;
  
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}


int main() {
    
    int l,x,i,j;
    int no=0;
	scanf("%d%d",&l,&x);
    for(i=1;i<=l;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(gcd(i,j)==x)
            no++;
        }
        
    }

    printf("%d",no);
	return 0;
}
