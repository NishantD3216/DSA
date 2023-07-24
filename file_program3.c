#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    FILE *fp1;
    int num;
    fp1=fopen("number.txt","r");
    if(fp1==NULL)
    {
        printf("File number.txt does not exist\n");
        exit(0);
    }
    fscanf(fp1,"%d",&num);
    printf("Number read from file is %d\n",num);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
