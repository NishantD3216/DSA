#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdio.h>

void swap(char str[]);

int main() {
    char str[100];
    printf("enter: ");
    scanf("%s",str);
    if(strlen(str)%2==0)
    swap(str);
    else
    printf("invalid length\n");

}
void swap(char str[])
{
    int i, temp;
    for(int i=0;str[i]!='0';i+=2)
    {
        temp=str[i];
        str[i]=str[i+1];
        str[i+1]=temp;
    }
    for(i=0;str[i]!='0';i++)
    printf("%s",str[i]);

}
