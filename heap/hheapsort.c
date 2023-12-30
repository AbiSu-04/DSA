// #include <stdio.h>
// void swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }
// void heapify(int arr[], int n, int i)
// {
//     int largest = i;
//     int l = 2 * i + 1;
//     int r = 2 * i + 2;

//     if (l < n && arr[l] > arr[largest])
//     {
//         largest = l;
//     }
//     if (r < n && arr[r] > arr[largest])
//     {
//         largest = r;
//     }
//     if (largest!= i)
//     {
//         swap(&arr[i], &arr[largest]);
//         heapify(arr, n, largest);
//     }
// }
// void heapSort(int arr[], int n) 
// {
//     for (int i = n / 2 - 1; i >= 0; i--)
//     {
//         heapify(arr, n, i);
//     }
//     for (int i = n - 1; i > 0; i--)
//     {
//         heapify(arr, i, 0);
//     }
// }
// void printArray(int arr[], int n)
// {
//     for (int i = 0; i < n; ++i)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// int main()
// {
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     heapSort(arr, n);

//     printf("Sorted array is \n");
//     printArray(arr, n);
//     return 0;
// }

//verified
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}
void heapSort2(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}
int extractMin(int *arr, int *n) {
    if (*n <= 0) {
        printf("Heap is empty\n");   
        return -1;  
    }
    int minVal = arr[0];
    arr[0] = arr[(*n) - 1];
    (*n)--;
    minHeapify(arr, *n, 0);

    return minVal;
}
int extractMax(int *arr, int *n) {
    if (*n <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int maxVal = arr[0];
    arr[0] = arr[(*n) - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);

    return maxVal;
}

void deleteMin(int *arr, int *n) {
    if (*n <= 0) {
        printf("Heap is empty\n");
        return;
    }

    arr[0] = arr[(*n) - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
}

void deleteMax(int *arr, int *n) {
    if (*n <= 0) {
        printf("Heap is empty\n");
        return;
    }

    arr[0] = arr[(*n) - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {6, 3, 9, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array using Heap Sort: ");
    printArray(arr, n);

    deleteMin(arr, &n);
    printf("Array after deleting minimum element: ");
    printArray(arr, n);
    heapSort2(arr,n);
    deleteMax(arr, &n);
    printf("Array after deleting maximum element: ");
    printArray(arr, n);

    return 0;
}
