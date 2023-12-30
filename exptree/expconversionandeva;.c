#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return 1;
    else
        return 0;
}

int precedence(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else
        return 0;
}

char *convert(char infix[],char postfix[])
{
    char stack[strlen(infix)];
    int i,j,top;
    for(i=0,j=0,top=-1;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i];
            // postfix[j++]=' ';
        }
        else if(infix[i]=='(')
        {
            stack[++top]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                postfix[j++]=stack[top--];
                // postfix[j++]=' ';
            }
            top--;
        }
        else if(isOperator(infix[i]))
        {
            while(precedence(stack[top])>=precedence(infix[i]))
            {
                postfix[j++]=stack[top--];
                // postfix[j++]=' ';
            }
            stack[++top]=infix[i];
        }
    }
    while(top!=-1)
    {
        postfix[j++]=stack[top--];
        // postfix[j++]=' ';
    }
    postfix[j]='\0';
    return postfix;
}

int evaluatePostfix(char* postfix) {
    int stack[strlen(postfix)];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i]))
            stack[++top] = postfix[i] - '0';
        else {
            int val1 = stack[top--];
            int val2 = stack[top--];
            switch (postfix[i]) {
                case '+': stack[++top] = val2 + val1; break;
                case '-': stack[++top] = val2 - val1; break;
                case '*': stack[++top] = val2 * val1; break;
                case '/': stack[++top] = val2 / val1; break;
            }
        }
    }
    return stack[top];
}

int main()
{
    char infix[100],postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    printf("The postfix expression is: %s",convert(infix,postfix));
    printf("\nThe evaluated expression is: %d", evaluatePostfix(postfix));
    return 0;
}


// //find sum of bst
//  #include<stdio.h>
//  #include<stdlib.h>
//  struct node
//  {
//     int data;
//     struct node *left,*right;
// };
// struct node *root=NULL;
// struct node *insert(struct node *root,int data)
// {
//     if(root==NULL)
//     {
//         root=(struct node *)malloc(sizeof(struct node));
//         root->data=data;
//         root->left=root->right=NULL;
//     }
//     else if(data<root->data)
//         root->left=insert(root->left,data);
//     else if(data>root->data)
//         root->right=insert(root->right,data);
//     return root;
// }
// int n= 0;
// int sum(struct node *root)
// {
    
//     if (root!=NULL){
//         sum(root->left);
//         n=n+root->data;
//         printf("%d",n);
//         sum(root->right);
//         return n;
//     }
// }
// int main()
// {
//     int n,data;
//     printf("Enter the number of nodes: ");
//     scanf("%d",&n);
//     printf("Enter the data for the nodes: ");
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&data);
//         root=insert(root,data);
//     }
//     printf("The sum of the nodes is: %d",sum(root));
//     return 0;
// }

