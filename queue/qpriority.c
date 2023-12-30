//array
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int empty(int size) {
    return (size == 0);
}

int full(int size) {
    return (size == MAX);
}

void display(int data[], int priority[], int size) {
    if (empty(size)) {
        printf("\nEmpty Queue\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("Data: %d Priority: %d\n", data[i], priority[i]); // Added newline character
    }
}

void enqueue(int data[], int priority[], int* size, int newData, int newPriority) {
    if (full(*size)) {
        printf("\nQueue Overflow\n");
        return;
    }
    if (empty(*size)) {
        data[0] = newData;
        priority[0] = newPriority;
        (*size)++;
        return;
    }
    int i = (*size) - 1;
    while (i >= 0 && priority[i] > newPriority) {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }
    data[i + 1] = newData;
    priority[i + 1] = newPriority;
    (*size)++;
}

int dequeue(int data[], int priority[], int* size) {
    if (empty(*size)) {
        printf("\nQueue Underflow\n");
        return -1;
    }
    int value = data[0];
    int priorityDequeued = priority[0];

    for (int i = 1; i < (*size); i++) {
        data[i - 1] = data[i];
        priority[i - 1] = priority[i];
    }
    (*size)--;
    printf("Dequeued: Value = %d, Priority = %d\n", value, priorityDequeued);
    return value;
}

int main() {
    int data[MAX];
    int priority[MAX];
    int size = 0;
    display(data, priority, size);
    enqueue(data, priority, &size, 10, 2);
    enqueue(data, priority, &size, 20, 1);
    enqueue(data, priority, &size, 15, 1);
    display(data, priority, size);
    dequeue(data,priority,&size);
    dequeue(data,priority,&size);
    display(data, priority, size);
    dequeue(data,priority,&size);
    display(data, priority, size);
    dequeue(data,priority,&size);
}

// // linked list

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     int prio;
//     struct Node *next;
// }*front = NULL;
// void enqueue(int data, int prio) {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->prio = prio;

//     if (front == NULL || prio < front->prio) {
//         newNode->next = front;
//         front = newNode;
//     } else {
//         struct Node *current = front;
//         while (current->next != NULL && current->next->prio <= prio) {
//             current = current->next;
//         }
//         newNode->next = current->next;
//         current->next = newNode;
//     }
// }

// void dequeue() {
//     if (front == NULL) {
//         printf("Queue is empty.\n");
//     } else {
//         struct Node *temp = front;
//         front = front->next;
//         printf("Dequeued element: %d\n", temp->data);
//         free(temp);
//     }
// }

// void print() {
//     if (front == NULL) {
//         printf("Queue is empty.\n");
//     } else {
//         struct Node *current = front;
//         printf("Queue elements: ");
//         while (current != NULL) {
//             printf("(%d, %d) ", current->data, current->prio);
//             current = current->next;
//         }
//         printf("\n");
//     }
// }

// int main() {
//     int data,prio;
//     printf("Enter the elements");
//     for(int i=0;i<5;i++){
//         scanf("%d%d",&data, &prio);
//         enqueue(data, prio);
//     }
//     print();
//     dequeue();
//     print();
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// struct element{
//     int value;
//     int priority;
// };

// struct element pr[100000];
// int size = -1;

// void enqueue(int value, int priority){
//     size++;
//     pr[size].value = value;
//     pr[size].priority = priority;
// }

// int peek(){
//     if(size == -1){
//         printf("Priority queue is empty\n");
//         return INT_MIN;
//     }
//     int maxPriority = pr[0].priority;
//     int index = 0;
//     for (int i = 1; i <= size; i++) {
//         if (pr[i].priority > maxPriority) {            // descending priority  , < ascending
//             maxPriority = pr[i].priority;
//             index = i;
//         }
//     }
//     return index;
// }

// int dequeue() {
//     int index = peek();

//     struct element highestPriority = pr[index];

//     for (int i = index; i < size; i++) {
//         pr[i] = pr[i + 1];
//     }
//     size--; 
//     return highestPriority.value;
// }
// void display(){
//   if(size==-1)
//    printf("Empty");
//   for(int i=0;i<=size;i++){
//     printf("%d ",pr[i].value);
//   }
//   printf("\n");
// }
// int main() {
//     enqueue(10, 2);
//     enqueue(14, 4);
//     enqueue(16, 1);
//     enqueue(12, 3);
//     display();
//     while (size >= 0) {
//         int highestPriorityValue = dequeue();
//         printf("Deleted element:%d\nqueue:", highestPriorityValue);
//         display();
//     }

//     return 0;
// }
