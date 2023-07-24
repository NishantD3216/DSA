#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void changecase(char str[100])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]+32;
        else if(str[i]>='a'&&str[i]<='z')
            str[i]=str[i]-32;
    }
    printf("\n%s\n",str);
}

void change_all_upper(char str[100])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a'&&str[i]<='z')
            str[i]=str[i]-32;
    }
    printf("\n%s\n",str);
}

void change_all_lower(char str[100])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]+32;
    }
    printf("\n%s\n",str);
}

int upper(char str[100])
{
    int count=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        //if(str[i]>='A'&&str[i]<='Z')
        if(isupper(str[i]))
        {
            count++;
        }
    }
    return count;
}

int lower(char str[100])
{
    int count=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        //if(str[i]>='a'&&str[i]<='z')
        if(islower(str[i]))
        {
            count++;
        }
    }
    return count;
}

int ASCII(char str[100])
{
    int count=0;
    for(int i=0;str[i]!='\0';i++)
    {
        printf("%c=%d\n",str[i],str[i]);
        count++;
    }
    return count;
}

int main()
{
    char str[100];
    int count,up,low;
    printf("Enter the sentences\n");
    scanf("\n%[^\n]s \n",str);
    count=ASCII(str);
    up=upper(str);
    low=lower(str);
    changecase(str);
    change_all_upper(str);
    change_all_lower(str);
    printf("\n no of characters=%d",count);
    printf("\n no of upper characters=%d\n no of lower characters=%d",up,low);
    return 0;
}
