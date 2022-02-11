#include <stdio.h>

int main()
{
    for(int i=1;i<=1000;++i)
    {
        if(i%6)
        {
            for(int m=i;(m>0);m/=10) if (m%10==6) goto l;
            l:
            printf("%d,",i);
            continue;
        }
        printf("Shaggy,");
    }
    return 0;
}

