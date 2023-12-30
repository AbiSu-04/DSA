// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// void insert(int *a, int data, int index) {
//     if (a[index] == 0) {
//         a[index] = data;
//     } else if (data < a[index]) {
//         insert(a, data, 2 * index + 1);
//     } else {
//         insert(a, data, 2 * index + 2);
//     }
// }

// void display(int *a, int i) {
//     if (a[2 * i + 1] != 0) {
//         display(a, 2 * i + 1);
//     }
//     printf("%d ", a[i]);  // Print space after each number
//     if (a[2 * i + 2] != 0) {
//         display(a, 2 * i + 2);
//     }
// }

// int search(int *a, int data, int index) {
//     if (data == a[index]) {
//         return index;
//     } else if (data < a[index]) {
//         return search(a, data, 2 * index + 1);
//     } else {
//         return search(a, data, 2 * index + 2);
//     }
//     return -1;
// }

// void deletion(int *a, int data) {
//     int index = search(a, data, 0);
//     if (index == -1) {
//         printf("Element not found\n");
//         return;
//     } else {
//         if (a[2 * index + 1] == 0 && a[2 * index + 2] == 0) {
//             a[index] = 0;
//         } else if (a[2 * index + 1] != 0 && a[2 * index + 2] == 0) {
//             a[index] = a[2 * index + 1];
//             a[2 * index + 1] = 0;
//         } else if (a[2 * index + 1] == 0 && a[2 * index + 2] != 0) {
//             a[index] = a[2 * index + 2];
//             a[2 * index + 2] = 0;
//         } else {
//             int temp = a[2 * index + 2];
//             while (a[2 * temp + 1] != 0) {
//                 temp = a[2 * temp + 1];
//             }
//             a[index] = a[temp];
//             a[temp] = 0;
//         }
//     }
// }

// int predecessor(int *a, int index) {
//     int i = index;
//     if (a[i + 1] != 0) {
//         while (a[2 * i + 2] != 0) {
//             i = 2 * i + 2;
//         }
//     }
//     return a[i];
// }

// void deleteNode(int *a, int index, int key) {
//     if (a[index] == 0) {
//         return;
//     } else if (a[index] > key) {
//         deleteNode(a, 2 * index + 1, key);
//     } else if (a[index] < key) {
//         deleteNode(a, 2 * index + 2, key);
//     } else {
//         if (a[2 * index + 1] == 0) {
//             a[index] = a[2 * index + 2];
//             deleteNode(a, 2 * index + 2, a[2 * index + 2]);
//         } else if (a[2 * index + 2] == 0) {
//             // Node with only left child
//             a[index] = a[2 * index + 1];
//             deleteNode(a, 2 * index + 1, a[2 * index + 1]);
//         } else {
//             // Node with two children, replace with predecessor
//             int temp = predecessor(a, 2 * index + 1);
//             a[index] = temp;
//             deleteNode(a, 2 * index + 1, temp);
//         }
//     }
// }

// int main() {
//     printf("Enter the no of elements:");
//     int elements;
//     scanf("%d", &elements);
//     int *a = (int *)calloc(pow(2, elements) - 1, sizeof(int));
//     for (int i = 0; i < elements; i++) {
//         printf("Enter the data:");
//         int data;
//         scanf("%d", &data);
//         insert(a, data, 0);
//     }
//     display(a, 0);
//     printf("\n");
//     int key;
//     printf("Enter the element to delete: ");
//     scanf("%d", &key);
//     deleteNode(a, 0, key);
//     display(a, 0);

//     free(a);  // Don't forget to free allocated memory
//     return 0;
// }


//this is final working

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insert(int *a, int data, int index) {
    if (a[index] == 0) {
        a[index] = data;
    } else if (data < a[index]) {
        insert(a, data, 2 * index + 1);
    } else {
        insert(a, data, 2 * index + 2);
    }
}

void display(int *a, int i) {
    if (*(a + 2 * i + 1) != 0) {
        display(a, 2 * i + 1);
    }
    printf("%d ", *(a + i));
    if (*(a + 2 * i + 2) != 0) {
        display(a, 2 * i + 2);
    }
}

int search(int *a, int data, int index) {
    if (data == a[index]) {
        return index;
    } else if (data < a[index]) {
        return search(a, data, 2 * index + 1);
    } else {
        return search(a, data, 2 * index + 2);
    }
    return -1;
}

int predecessor(int *a, int index) {
    index = 2 * index + 1; // Move to the left child

    while (a[2 * index + 2] != 0) {
        index = 2 * index + 2;
    }

    return a[index];
}

void deleteNode(int *a, int index, int key) {
    if (a[index] == 0) {
        return;
    } else if (key < a[index]) {
        deleteNode(a, 2 * index + 1, key);
    } else if (key > a[index]) {
        deleteNode(a, 2 * index + 2, key);
    } else {
        if (a[2 * index + 1] == 0) {
            a[index] = a[2 * index + 2];
        } else if (a[2 * index + 2] == 0) {
            a[index] = a[2 * index + 1];
        } else {
            int temp = predecessor(a, index);
            a[index] = temp;
            deleteNode(a, 2 * index + 1, temp);
        }
    }
}

void deletion(int *a, int data) {
    int index = search(a, data, 0);
    if (index == -1) {
        printf("Element not found\n");
        return;
    } else {
        deleteNode(a, 0, data);
    }
}

int main() {
    printf("Enter the no of elements:");
    int elements;
    scanf("%d", &elements);
    int *a = (int *)calloc(pow(2, elements) - 1, sizeof(int));
    for (int i = 0; i < elements; i++) {
        printf("Enter the data:");
        int data;
        scanf("%d", &data);
        insert(a, data, 0);
    }

    printf("Binary Search Tree: ");
    display(a, 0);

    int key;
    printf("\nEnter the element to delete: ");
    scanf("%d", &key);
    deletion(a, key);

    printf("Updated Binary Search Tree: ");
    display(a, 0);

    free(a);
    return 0;
}

// // traversal
// // binary search tree with array
// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 100
// int arr[MAX];
// int count = 0;
// void insert(int data);
// void inorder(int i);
// void preorder(int i);
// void postorder(int i);
// int main(){
//     int data;
//     printf("Enter the data for the root node: ");
//     scanf("%d", &data);
//     insert(data);
//     while (1) {
//         printf("Enter data for the node (-1 to stop): ");
//         scanf("%d", &data);
//         if (data == -1) {
//             break;
//         }
//         insert(data);
//     }
//     printf("\nInorder Traversal of the Binary Search Tree: ");
//     inorder(0);
//     printf("\n");
//     printf("\nPreorder Traversal of the Binary Search Tree: ");
//     preorder(0);
//     printf("\n");
//     printf("\nPostorder Traversal of the Binary Search Tree: ");
//     postorder(0);
//     printf("\n");
//     return 0;
// }
// void insert(int data){
//     int i = 0;
//     while (arr[i] != 0) {
//         if (arr[i] < data) {
//             i = 2 * i + 2;
//         } else {
//             i = 2 * i + 1;
//         }
//     }
//     arr[i] = data;
//     count++;
// }
// void inorder(int i){
//     if (i < count && arr[i] != 0) {
//         inorder(2 * i + 1);
//         printf("%d -> ", arr[i]);
//         inorder(2 * i + 2);
//     }
// }
// void preorder(int i){
//     if (i < count && arr[i] != 0) {
//         printf("%d -> ", arr[i]);
//         preorder(2 * i + 1);
//         preorder(2 * i + 2);
//     }
// }
// void postorder(int i){
//     if (i < count && arr[i] != 0) {
//         postorder(2 * i + 1);
//         postorder(2 * i + 2);
//         printf("%d -> ", arr[i]);
//     }
// }
