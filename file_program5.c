#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct players
{
    char name[20],country[20];
    int runs,rank;
};
void display_file(FILE *fp3,struct players p1[10]);
int main()
{
    FILE *fp1,*fp2,*fp3;
    struct players p1[10];
    fp1=fopen("players.txt","r");
    fp2=fopen("playersoutput.txt","w");
    fp3=fopen("playersruns.txt","w");
    if(fp1==NULL)
    {
        printf("File players.txt does not exist\n");
        exit(0);
    }
    for(int i=0;i<4;i++)
    {
        fscanf(fp1,"%s%s%d%d",p1[i].name,p1[i].country,&p1[i].runs,&p1[i].rank);
    }

    printf("Player details\n");
    printf("Name\tcountry\truns\trank\n");
    for(int i=0;i<4;i++)
    {
        printf("%s\t%s\t%d\t%d\n",p1[i].name,p1[i].country,p1[i].runs,p1[i].rank);
        fprintf(fp2,"%s\t%s\t%d\t%d\n",p1[i].name,p1[i].country,p1[i].runs,p1[i].rank);
    }
    display_file(fp3,p1);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
void display_file(FILE *fp3,struct players p1[10])
{
    int i;
    for(i=0;i<4;i++)
    {
        if(p1[i].runs>8000)
        {
            fprintf(fp3,"%s\t%s\t%d\t%d\t",p1[i].name,p1[i].country,p1[i].runs,p1[i].rank);
            printf("%s\t%s\t%d\t%d\n",p1[i].name,p1[i].country,p1[i].runs,p1[i].rank);
        }
    }
}
