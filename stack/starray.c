//normal stack functioning
#include <stdio.h>
void push(int *array, int *top, int size) {
    int value;
    printf("Enter the element to push: ");
    scanf("%d", &value);
    if (*top == size - 1) {
        printf("Overflow\n");
    } else {
        (*top)++;
        array[*top] = value;
        printf("Element %d pushed to the stack.\n", value);
    }
}
void pop(int *array,int *top, int size){
    if(*top==-1){
        printf("Underflow\n");
    }
    else{
        printf("Element %d popped\n",array[*top]);
        (*top)--;
    }
}

int main() {
    int top = 3; // Initializing top of the stack
    int array[5] = {1, 2, 3, 4}; // Added 0 to show the empty slot
    int size = sizeof(array) / sizeof(array[0]);
    //push(array, &top, size);
    pop(array,&top,size);

    // Print the updated array to check the changes
    printf("Updated Array: ");
    for (int i = 0;i<=top; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}











//CONVERSION OF INFIX TO POSTFIX
//STACK using Linked List
//In stack using linked list, we don't check for overflow condition as the size is not fixed but in arrays we do because size is fixed
// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data; //4 bytes for value and 4 for address so 8 bytes to store a value in stack  
//     struct node *next;
// };
// struct node *top=NULL;
// void display(){
//     struct node *print;
//     print=top;
//     printf("The Stacks is:\n");
//     if(top==NULL){
//         printf("List is Empty");
//     }
//     else{
//         while(print!=NULL){
//             printf("%d\n",print->data);
//             print=print->next;
//         }
//     }
// }

// void push(int x){
//     struct node *newNode=(struct node*)malloc(sizeof(struct node));
//     newNode->data=x;
//     newNode->next=top; //the first element to
//     top=newNode;
// }
// void peek(){ //prints top element of the stack without deleting it
//     if(top==NULL){
//         printf("Stack is Empty");
//     }
//     else{
//         printf("Top element is: %d",top->data);
//     }
// }
// void pop(){
//     struct node *del;
//     if(top==NULL){
//         printf("Stack is empty");
//     }
//     else{
//         del=top;
//         top=top->next;
//         printf("Deleted element is:%d",top->data);
//         free(del); //we print the data and delete it by freeing the element 
//     }
// }