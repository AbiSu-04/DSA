// circ using array
// #include <stdio.h>
// #include <stdlib.h>

// int front = -1;
// int rear = -1;

// void enqueue(int *array, int data, int size) {
//     if ((rear == size - 1 && front == 0) || (front - rear == 1)) {
//         printf("\nOverflow");
//         return;
//     } else if (front == -1 && rear == -1) {
//         front++;
//         rear++;
//         array[front] = data;
//     } else if (rear == size - 1) {
//         rear = 0;
//         array[rear] = data;
//     } else {
//         rear++;
//         array[rear] = data;
//     }
// }

// void dequeue(int *array, int size) {
//     if (front == -1 && rear == -1) {
//         printf("Underflow");
//     } else if (front == rear) {
//         printf("\nDeleted element: %d", array[front]);
//         front = rear = -1;
//     } else if (front == size - 1) {
//         printf("\nDeleted element: %d", array[front]);
//         front = 0;
//     } else {
//         printf("\nDeleted element: %d", array[front]);
//         front++;
//     }
// }

// void printqueue(int *array, int size) {
//     printf("\n");
//     if (front == -1 && rear == -1) {
//         printf("Empty queue");
//         return;
//     }
//     if (rear >= front) {
//         for (int i = front; i < rear + 1; i++)
//             printf("%d ", array[i]);
//     } else {
//         for (int i = front; i < size; i++) {
//             printf("%d ", array[i]);
//         }
//         for (int i = 0; i < rear + 1; i++) {
//             printf("%d ", array[i]);
//         }
//     }
//     printf("\n");
// }

// int main() {
//     int n;
//     printf("Enter the number of elements in the array:");
//     scanf("%d", &n);
//     int *arr1 = (int *)malloc(sizeof(int) * n);
//     enqueue(arr1, 6, n);
//     enqueue(arr1, 3, n);
//     enqueue(arr1, 9, n);
//     printqueue(arr1, n);
//     dequeue(arr1, n);
//     dequeue(arr1, n);
//     printqueue(arr1, n);
//     enqueue(arr1, 61, n);
//     enqueue(arr1, 31, n);
//     enqueue(arr1, 91, n);
//     printqueue(arr1, n);

//     // Free the allocated memory for the array
//     free(arr1);

//     return 0;
// }

// // linked list
// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *next;
// };

// struct Node *getnode(int data) {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// struct Node *front = NULL;
// struct Node *rear = NULL;

// void enqueue(int x) {
//     struct Node *newNode = getnode(x);

//     if (front == NULL && rear == NULL) {
//         front = rear = newNode;
//     } else {
//         rear->next = newNode;
//         rear = newNode;
//     }
//     rear->next = front;
// }

// void dequeue() {
//     struct Node *temp = front;
//     if (front == NULL && rear == NULL) {
//         printf("\nQueue is empty");
//     } else if (front == rear) {
//         printf("\nDeleted element: %d", front->data);
//         front = rear = NULL;
//     } else {
//         printf("\nDeleted element: %d", front->data);
//         front = front->next;
//         rear->next = front;
//     }
//     free(temp);
// }

// void printNode() {
//     printf("\n");
//     if (front == NULL) {
//         printf("Empty queue");
//         return;
//     }
//     struct Node *current = front;
//     while (current->next != front) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("%d ", current->data);
//     printf("\n");
// }

// int main() {
//     enqueue(5);
//     enqueue(18);
//     enqueue(15);
//     printNode();
//     dequeue();
//     dequeue();
//     dequeue();
//     dequeue();
//     printNode();
//     enqueue(51);
//     enqueue(181);
//     enqueue(151);
//     printNode();

//     return 0;
// }


