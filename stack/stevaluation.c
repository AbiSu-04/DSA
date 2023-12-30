//array
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int push(int* arr, int top, int size, int data) {
    if (top == size - 1) {
        printf("Overflow\n");
    } else {
        top = top + 1;
        arr[top] = data;
    }
    return top;
}

int pop(int* arr, int size, int* top) {
    if (*top == -1) {
        printf("Underflow\n");
        return -99;
    }
    return arr[(*top)--];
}

int evaluate(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                printf("Division by zero\n");
                exit(1);
            }
        default:
            printf("Invalid operator: %c\n", op);
            exit(1);
    }
}

int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    int arr[size];
    int top = -1; // Initialize top to -1

    char expression[100];
    printf("Enter the postfix expression: ");
    scanf("%s", expression);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            int operand = expression[i] - '0'; // Convert character to integer
            top = push(arr, top, size, operand);
        } else {
            char operator = expression[i]; // Store operator as a character
            int operand2 = pop(arr, size, &top);
            int operand1 = pop(arr, size, &top);
            int result = evaluate(operand1, operand2, operator);
            top = push(arr, top, size, result);
        }
    }

    if (top == 0) {
        int finalResult = pop(arr, size, &top);
        printf("Result of postfix expression: %d\n", finalResult);
    } else {
        printf("Invalid postfix expression\n");
    }

    return 0;
}

// ll

// #include<stdio.h>
// #include<stdlib.h>
// struct Node{
//     int data;
//     struct Node* next;
// };
// struct Node* top = NULL;
// void push(int data){
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->next = top;
//     top = temp;
// }
// int pop(){
//     if(top == NULL){
//         printf("Underflow\n");
//         return -99;
//     }
//     struct Node* temp = top;
//     int data = temp->data;
//     top = top->next;
//     free(temp);
//     return data;
// }
// int evaluate(int operand1, int operand2, char op){
//     switch(op){
//         case '+':
//             return(operand1+operand2);
//         case '-':
//             return(operand1-operand2);
//         case '*':
//             return(operand1*operand2);
//         case '/':
//             return(operand1/operand2);
//     }
// }
// int main(){
//     char expression[100];
//     printf("Enter the postfix expression: ");
//     scanf("%s", expression);
//     for(int i=0; expression[i]!='\0'; i++){
//         if(isdigit(expression[i])){
//             push(expression[i]-'0');
//         }
//         else{
//             int operand2 = pop();
//             int operand1 = pop();
//             int result = evaluate(operand1, operand2, expression[i]);
//             push(result);
//         }
//     }
//     if(top->next == NULL){
//         printf("Result of postfix expression: %d\n", top->data);
//     }
//     else{
//         printf("Invalid postfix expression\n");
//     }
//     return 0;
// }