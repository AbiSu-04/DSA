#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return isalnum(ch);
}
// Function to build an expression tree from a postfix expression
TreeNode* buildExpressionTree(char postfix[]) {
    TreeNode* stack[100];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; ++i) {
        TreeNode* node = createNode(postfix[i]);

        if (isOperand(postfix[i])) {
            stack[++top] = node;
        } else {
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top];
}
// Function to evaluate an expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (isOperand(root->data)) {
        return root->data - '0';
    }
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);
    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0; // Invalid operator
    }
}
// Function to perform in-order traversal of the expression tree
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    char postfixExpression[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    TreeNode* root = buildExpressionTree(postfixExpression);

    printf("\nIn-order traversal of the expression tree: ");
    inOrderTraversal(root);

    int result = evaluateExpressionTree(root);
    printf("\n\nResult of the expression: %d\n", result);

    return 0;
}
