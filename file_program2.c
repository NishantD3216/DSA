#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp1,*fp2;
    char ch;
    fp1=fopen("name.txt","r");
    fp2=fopen("output.txt","w");
    if(fp1==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }
    while(!feof(fp1))
    {
        ch=getc(fp1);
        putc(ch,fp2);

    }
    fclose(fp1);
    fclose(fp2);
    return 0;

}
