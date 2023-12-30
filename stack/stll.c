// //normal stack
// #include <stdio.h>
// #include <stdlib.h>

// // Definition of a node in the linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to push an element onto the stack
// void push(struct Node** top, int value) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Stack Overflow\n");
//         return;
//     }

//     newNode->data = value;
//     newNode->next = *top;
//     *top = newNode;
//     printf("Element %d pushed to the stack.\n", value);
// }

// // Function to pop an element from the stack
// void pop(struct Node** top) {
//     if (*top == NULL) {
//         printf("Stack Underflow\n");
//         return;
//     }

//     struct Node* temp = *top;
//     *top = temp->next;
//     printf("Element %d popped from the stack.\n", temp->data);
//     free(temp);
// }

// // Function to display the elements in the stack
// void display(struct Node* top) {
//     struct Node* current = top;
//     printf("Stack: ");
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// int main() {
//     struct Node* top = NULL;
    
//     push(&top, 1);
//     push(&top, 2);
//     push(&top, 3);
    
//     display(top);
    
//     pop(&top);
//     pop(&top);
//     pop(&top);
//     pop(&top); // Trying to pop from an empty stack
    
//     display(top);
    
//     return 0;
// }