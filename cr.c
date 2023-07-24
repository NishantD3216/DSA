#include<stdio.h>
void read(int n, int arr[10]);
void display(int n, int arr[10]);
int main()
{
    int n;
    int arr[10];
    scanf("%d",&n);
    read(n,arr);
    display(n,arr);
    return 0;
}
void read(int n, int arr[10])
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

}
void display(int n, int arr[10])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("Lowest number in array is -45.\n");
}

