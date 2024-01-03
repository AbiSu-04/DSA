// iteration
#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
  if (arr[mid] == target) {
            return mid;
        }
 else if (arr[mid] < target) {
            low = mid + 1;     
   }
 else {
            high = mid - 1;        }
    }

    return -1; 
}

  int main() {
    int n,target;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);
   int arr[n];
    printf("Enter %d elements of the sorted array in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, n - 1, target);
     if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
}


// // recursion
#include <stdio.h>
int binarySearchRecursive(int *arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            return binarySearchRecursive(arr, target, mid + 1, right);

        else
            return binarySearchRecursive(arr, target, left, mid - 1);
    }
    return -1;
}

int main() {
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);

    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearchRecursive(arr, target, 0, n - 1);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in the array\n", target);
}