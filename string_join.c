#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void join(char fname[20],char lname[20]);
int main() {
    char fname[20],lname[20];
    scanf("%s",fname);
    scanf("%s",lname);
    printf("Welcome\t");
    join(fname,lname);
}
void join(char fname[20],char lname[20])
{
    int i=0,j=0;
    /*while(fname[i]!='\0')
    {i++;}
    fname[i++]=' ';
    while (lname[j]!='\0')
    {fname[i++]=lname[j++];}
    puts(fname);*/
    strcat(fname,lname);
    puts(fname);
}
