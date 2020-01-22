//Maximum contiguous array

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,sum=0,max=0;
    printf("Enter array size ");
    scanf("%d",&n);
    int *arr;
    arr=(int *)malloc(sizeof(int)*n);
    printf("Enter array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sum=arr[0];
    max=arr[0];
    for(i=1;i<n;i++)
    {
        if(sum+arr[i]>arr[i])
        {
            sum=sum+arr[i];
        }
        else
        {
            sum=arr[i];
        }
        if(sum>max)
        {
            max=sum;
        }
    }
    printf("%d",sum);
}