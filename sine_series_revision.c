#include<stdio.h>
#include<math.h>
#define PI 3.1415

float sine_series(float x_radian,int term);
int main()
{
    float x_radian,sum;
    float x_degree;
    int term;
    scanf("%f%d",&x_degree,&term);
    x_radian=x_degree*(PI/180);
    sum=sine_series(x_radian,term);
    if(term==0)
    {
        printf("Invalid input.\n");
    }
    else
    {
        printf("Sine value of %0.3f is: %0.3f\n",x_degree,sum);
    }
    return 0;
}
float sine_series(float x_radian,int term)
{
    float nume,deno,sum_series=0;
    int i;
    nume=x_radian;
    deno=1;
    i=1;
    do
    {
        term=nume/deno;
        sum_series=sum_series+term;
        nume=nume*x_radian*x_radian*(-1);
        deno=deno*(i+1)*(i+2);
        i=i+2;
    }while(fabs(term)>=0.00001);
    return sum_series;
}
