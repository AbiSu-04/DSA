
// array  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 char stack[100],infix[100],postfix[100];
 int top=-1;
void push(char c)
{
 if(top==(100-1))
 {
  printf("overflow");
 }
 else{
  stack[++top]=c;
 }
}
char pop()
{
 char c;
 if(top==-1)
 {
  printf("underflow");
 }
 c=stack[top--];
 return c;

}
int empty()
{
 if(top==-1)
 {
   return 1;
 }
 else{
   return 0;
 }
}
int precedance(char store)
{
 switch(store)
 {
  case '^':
     return 3;
  case '/':
  case '*':
     return 2;
  case '+':
  case '-':
      return 1;
  default:
      return 0;
 }
}

void print()
{
 int i=0;
 printf("the postfix expression is:");
 while(postfix[i])
 {
  printf("%c",postfix[i++]);
 }
 printf("\n");

}
void infixTopostfix()
{
 int i,j=0;
 char store,new;
 for(i=0;i<strlen(infix);i++){
   store=infix[i];
   switch(store)
   {
    case '(':
        push(store);
        break;
    case ')':
         while((new=pop())!='(')
            postfix[j++]=new;
         break;
    case '+':
    case '-':
    case '^':
    case '/':
    case '*':
          while(!empty()&&precedance(store)<=precedance(stack[top]))
               postfix[j++]=pop();
          push(store);
          break;
    default:
         postfix[j++]=store;
    }

  }
  while(!empty())

      postfix[j++]=pop();
   postfix[j]='\0';
}
int main()
{
 printf("enter infix expression:");
 gets(infix);
 infixTopostfix();
 print();
 return 0;
}


// // linked list
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_EXPRESSION_SIZE 100

// // Define a node structure for the linked list
// struct Node {
//     char data;
//     struct Node* next;
// };

// struct Node* top = NULL;

// char infix[MAX_EXPRESSION_SIZE];
// char postfix[MAX_EXPRESSION_SIZE];

// // Function to push a character onto the stack
// void push(char c) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         exit(1);
//     }
//     newNode->data = c;
//     newNode->next = top;
//     top = newNode;
// }

// // Function to pop a character from the stack
// char pop() {
//     char c;
//     if (top == NULL) {
//         printf("Underflow\n");
//         return '\0'; // Return a character that cannot be part of a valid infix expression
//     }
//     struct Node* temp = top;
//     c = temp->data;
//     top = top->next;
//     free(temp);
//     return c;
// }

// // Function to check if the stack is empty
// int isEmpty() {
//     return (top == NULL);
// }

// // Function to get precedence of an operator
// int precedence(char symbol) {
//     switch (symbol) {
//         case '^':
//             return 3;
//         case '/':
//         case '*':
//             return 2;
//         case '+':
//         case '-':
//             return 1;
//         default:
//             return 0;
//     }
// }

// // Function to print the postfix expression
// void print() {
//     printf("The postfix expression is: %s\n", postfix);
// }

// // Function to convert infix to postfix using linked list stack
// void infixToPostfix() {
//     int i, j = 0;
//     char symbol, newSymbol;
//     for (i = 0; i < strlen(infix); i++) {
//         symbol = infix[i];
//         switch (symbol) {
//             case '(':
//                 push(symbol);
//                 break;
//             case ')':
//                 while ((newSymbol = pop()) != '(')
//                     postfix[j++] = newSymbol;
//                 break;
//             case '+':
//             case '-':
//             case '^':
//             case '/':
//             case '*':
//                 while (!isEmpty() && precedence(symbol) <= precedence(top->data))
//                     postfix[j++] = pop();
//                 push(symbol);
//                 break;
//             default:
//                 postfix[j++] = symbol;
//         }
//     }
//     while (!isEmpty())
//         postfix[j++] = pop();
//     postfix[j] = '\0';
// }

// int main() {
//     printf("Enter infix expression: ");
//     fgets(infix, MAX_EXPRESSION_SIZE, stdin);
//     infixToPostfix();
//     print();
//     return 0;
// }
