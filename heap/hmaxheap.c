#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int i,int j)
{
    int temp=*(a+i);
    *(a+i)=*(a+j);
    *(a+j)=temp;
}
void heapifyup(int* a,int n,int i)
{
    while(i>0)
    {
        int parent=(i-1)/2;
        if(a[i]>a[parent])
        {
            swap(a,i,parent);
            i=parent;
        }
        else
            break;
    }
}
void heapifydown(int* a,int n,int i)
{
    while(1)
    {
        int max=i;
        int left=2*i+1;
        int right=2*i+2;
        //max=(left<n && a[left]>a[max])?left:max;
        //max=(right<n && a[right]>a[max])?right:max;
        if (left < n && a[left] > a[max]) {
    max = left;
}       
         if (right < n && a[right] > a[max]) {
    max = right;
}

        if(max!=i)
        {
            swap(a,i,max);
            i=max;
        }
        else
            break;
    }
}
void deletemax(int* a,int* n)
{
    int i;
    swap(a,0,(*n)-1);
    (*n)-=1;
    for(i=(*n)/2-1;i>=0;i--)
    {
        heapifydown(a,*n,i);
    }
}
int extractmax(int* a)
{
    return a[0];
}
void heapsort(int* a,int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        heapifydown(a,n,i);
    }
    for(i=n-1;i>0;i--)
    {
        swap(a,0,i);
        heapifydown(a,i,0);
    }
}
// int main()
// {
//     int i,j,n;
//     printf("Enter no of elements:");
//     scanf("%d",&n);
//     int* a=(int*)malloc(n*sizeof(int));
//     printf("Enter the elements:");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&*(a+i));
//     }
//     printf("Array:");
//     for(i=0;i<n;i++)
//     {
//         printf("%3d",*(a+i));
//     }
//     for(i=0;i<n;i++)
//     {
//         heapifyup(a,n,i);
//     }
//     printf("\nHeapify Up:");
//     for(i=0;i<n;i++)
//     {
//         printf("%3d",*(a+i));
//     }
//     printf("\nMax element:%2d",extractmax(a));
//     deletemax(a,&n);
//     printf("\nDelete Max:");
//     for(i=0;i<n;i++)
//     {
//         printf("%3d",*(a+i));
//     }
//     printf("\nMax element:%2d",extractmax(a));
//     heapsort(a,n);
//     printf("\nHeap Sort:");
//     for(i=0;i<n;i++)
//     {
//         printf("%3d",*(a+i));
//     }
// }





