#include<stdio.h>
#define MAX 2

int main()
{
	int i;
	printf("%c",201);//top-left
	for(i=0;i<10;i++)
	printf("%c",205);//horizantal line
	printf("%c\n",187);//top-right
	printf("%c",186);//vertical-line
	printf("%c ",2);
	printf("%-8s","l");
	printf("%c\n",186);
	printf("%c",200);//bottom left
	for(i=0;i<10;i++)
	printf("%c",205);//horizantal line
	printf("%c",188);//bottom right
	
}

/*199 = ¦
200 = +
201 = +
202 = -
203 = -
204 = ¦
205 = -
206 = +
207 = -
208 = -
209 = -
210 = -
211 = +
212 = +
213 = +
214 = +
215 = +
216 = +
*/
