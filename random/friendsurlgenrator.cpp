//url of all friends episode
//http://s.u4u.xyz/Series/Friends//S01/Friends%20S01E07%20480p%20Bluray%20TagName.mkv
#include<Stdio.h>


int main()
{
	int i=9,t=0;
	char url[]="http://s.u4u.xyz/Series/Friends//S01/Friends%20S01E",url2[]="%20480p%20Bluray%20TagName.mkv";
	FILE *fp;
	
	fp=fopen("Friends_season1.txt","w");
	while(1)
	{
		t++;
		fprintf(fp,"\n%s%02d%s",url,i,url2);
		i++;
		if(i>24)
		break;
	}
}
