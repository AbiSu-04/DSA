#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
        if(a[i]<a[parent])
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
        int min=i;
        int left=2*i+1;
        int right=2*i+2;
      if (left < n && a[left] < a[min]) {
    min = left;
} 
     if (right < n && a[right] < a[min]) {
    min = right;
}

        if(min!=i)
        {
            swap(a,i,min);
            i=min;
        }
        else
            break;
    }
}
void deletemin(int* a,int* n)
{
    int i;
    swap(a,0,(*n)-1);
    (*n)-=1;
    for(i=(*n)/2-1;i>=0;i--)
    {
        heapifydown(a,*n,i);
    }
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
int main()
{
    int i,j,n;
    printf("Enter no of elements:");
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&*(a+i));
    }
    printf("\nArray:");
    for(i=0;i<n;i++)
    {
        printf("%3d",*(a+i));
    }
    for(i=0;i<n;i++)
    {
        heapifyup(a,n,i);
    }
    printf("\nHeapify Up:");
    for(i=0;i<n;i++)
    {
        printf("%3d",*(a+i));
    }
    printf("\nMin element:%2d",a[0]);
    deletemin(a,&n);
    printf("\nDelete Min:");
    for(i=0;i<n;i++)
    {
        printf("%3d",*(a+i));
    }
    printf("\nMin element:%2d",a[0]);
    heapsort(a,n);
    printf("\nHeap Sort:");
    for(i=0;i<n;i++)
    {
        printf("%3d",*(a+i));
    }
}




// //rama min heap


// #include <stdio.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void minHeapify(int arr[], int n, int i) {
//     int smallest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[left] < arr[smallest])
//         smallest = left;

//     if (right < n && arr[right] < arr[smallest])
//         smallest = right;

//     if (smallest != i) {
//         swap(&arr[i], &arr[smallest]);
//         minHeapify(arr, n, smallest);
//     }
// }

// int extractmin(int *arr) {
//     return arr[0];
// }

// void deletemin(int *arr, int *n) {
//     arr[0] = arr[(*n) - 1];
//     (*n)--;
//     minHeapify(arr, *n, 0);
// }

// void heapsort(int *arr, int n) {
//     for (int i = n / 2 - 1; i >= 0; i--) {
//         minHeapify(arr, n, i);
//     }

//     for (int i = n - 1; i >= 1; i--) {
//         swap(&arr[0], &arr[i]);
//         minHeapify(arr, i, 0);
//     }
// }

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; ++i)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
//     int arr[] = {6, 3, 9, 8, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     printf("Before minHeapify: ");
//     printArray(arr, n);

//     for (int i = (n / 2) - 1; i >= 0; i--)
//         minHeapify(arr, n, i);

//     printf("After minHeapify: ");
//     printArray(arr, n);

//     printf("\n");

//     heapsort(arr, n);

//     printf("Sorted array is:\n");
//     printArray(arr, n);

//     printf("\n");

//     printf("Minimum element: %d\n", extractmin(arr));

//     deletemin(arr, &n);

//     printf("After deleting minimum element: ");
//     printArray(arr, n);

//     return 0;
// }