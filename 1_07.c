#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void increment(char d, int s);
int main()
{
    int s;
    char d;
    scanf("%c%d",&d,&s);
    increment(d,s);
    return 0;
}
void increment(char d, int s)
{
    int incremented_salary;
    switch(d)
    {
        case 'S':
            if(s>100000&&s<200000)
            {
                incremented_salary= s+(s*0.05);
                printf("%d\n",incremented_salary);
            }
            else if(s>70000&&s<100000)
            {
                incremented_salary=s+(s*0.03);
                printf("%d\n",incremented_salary);
            }
            else if(s>40000&&s<70000)
            {
                incremented_salary=s+(s*0.03);
                printf("%d\n",incremented_salary);
            }
            break;
        case 'A':
            if(s>80000&&s<160000)
            {
                incremented_salary=s+(s*0.04);
                printf("%d\n",incremented_salary);
            }
            else if(s>50000&&s<80000)
            {
                incremented_salary=s+(s*0.05);
                printf("%d\n",incremented_salary);
            }
            break;
        case 'P':
            if(s>100000&&s<200000)
            {
                incremented_salary=s+(s*0.09);
                printf("%d\n",incremented_salary);
            }
            else if(s>60000&&s<100000)
            {
                incremented_salary=s+(s*0.07);
                printf("%d\n",incremented_salary);
            }
            else if(s>40000&&s<60000)
            {
                incremented_salary=s+(s*0.05);
                printf("%d\n",incremented_salary);
            }
            break;
        default:printf("Invalid designation\n");
            break;
    }
    return 0;
}
