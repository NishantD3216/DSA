#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    FILE *fp1,*fp2;
    int num[10];
    fp1=fopen("number.txt","r");
    fp2=fopen("numberoutput.txt","w");
    if(fp1==NULL)
    {
        printf("File number.txt does not exist\n");
        exit(0);
    }
    for(int i=0;i<4;i++)
    {
        fscanf(fp1,"%d",&num[i]);
    }
    printf("Number read from file and sent to another file named numberoutput.txt \n");
    for(int i=0;i<4;i++)
    {
        fprintf(fp2,"%d\t",num[i]);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

