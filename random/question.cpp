

//the function should be able to delete a record by entering the book code, the code works properly for the most part. while deleting a record the last record gets printed twice and if we are deleting a record in between everything under that gets also deleted.

#include <stdio.h>
#include <conio.h>
#include <string.h>
FILE *fp;
int cd,b;
struct data
    {
     int bn;
     char bname[50],aut[20],g[10],sts[1];
     int yr;
   }d;
int main()
{
 FILE *tp;
 int bid;
 fp=fopen("db.txt","r");
 tp=fopen("temp.txt","w");
 printf("\n\n\t\t\t\tCURRENT CATALOG ITEM \n\t\t\t\t____________________\n");
 fseek(fp,0,SEEK_END);
    cd=ftell(fp);
 fseek(fp,0,SEEK_SET);
 printf("\n*******************************************************************************************");
 printf("\nbook code\t|book name\t|author\t\t|genre\t\t|year\t\t|available|" );
 printf("\n*******************************************************************************************");
 while(ftell(fp)!=cd)
 {
    fscanf(fp,"%d %s %s %s %d %s",&d.bn,&d.bname,&d.aut,&d.g,&d.yr,&d.sts);
    printf("\n%d\t\t|%s\t\t|%s\t\t|%s\t\t|%d\t\t|%s\t  |",d.bn,d.bname,d.aut,d.g,d.yr,d.sts);
 }
 printf("\n*******************************************************************************************");
 fseek(fp,0,SEEK_SET);
 printf("\nEnter the book you want to delete(book code):");
 scanf("%d",&bid);


  while (ftell(fp)!=cd)
  {
           fscanf(fp,"%d %s %s %s %d %s",&d.bn,&d.bname,&d.aut,&d.g,&d.yr,&d.sts);
           if (feof(fp))
             break;
           if (bid!=d.bn)
            fprintf(tp,"%d %s %s %s %d %s\n",d.bn,d.bname,d.aut,d.g,d.yr,d.sts);
  }

    fclose(fp);
    fclose(tp);
    remove("db.txt");
    rename("temp.txt","db.txt");
    fp=fopen("db.txt","r");
    fseek(fp,0,SEEK_END);
       cd=ftell(fp);
    fseek(fp,0,SEEK_SET);
    printf("\n\n\t\t\t\tNEW CATALOG ITEM \n\t\t\t\t________________\n");
    printf("\n*******************************************************************************************");
    printf("\nbook code\t|book name\t|author\t\t|genre\t\t|year\t\t|available|" );
    printf("\n*******************************************************************************************");
    while (ftell(fp)!=cd)
    {
       fscanf(fp,"%d %s %s %s %d %s",&d.bn,&d.bname,&d.aut,&d.g,&d.yr,&d.sts);
       printf("\n%d\t\t|%s\t\t|%s\t\t|%s\t\t|%d\t\t|%s\t  |",d.bn,d.bname,d.aut,d.g,d.yr,d.sts);
    }
    printf("\n*******************************************************************************************");
 fclose(fp);


}
