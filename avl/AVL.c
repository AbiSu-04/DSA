#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* leftRotate(Node *p) {
    Node *c = p->right;
    p->right = c->left;
    c->left = p;
    return c;
}

Node* rightRotate(Node *p) {
    Node *c = p->left;
    p->left = c->right;
    c->right = p;
    return c;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int lh, rh;
    lh = height(node->left);
    rh = height(node->right);
    return lh > rh ? lh + 1 : rh + 1;
}

Node* rotate(Node *p) {
    if (height(p->left) - height(p->right) > 1) {
        if (height((p->left)->left) > height((p->left)->right)) {
            return rightRotate(p);
        }
        if (height((p->left)->left) < height((p->left)->right)) {
            p->left = leftRotate(p->left);
            return rightRotate(p);
        }
    }
    if (height(p->left) - height(p->right) < -1) {
        if (height((p->right)->left) < height((p->right)->right)) {
            return leftRotate(p);
        }
        if (height((p->right)->left) > height((p->right)->right)) {
            p->right = rightRotate(p->right);
            return leftRotate(p);
        }
    }
    return p;
}

Node* getNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = getNode(data);
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return rotate(root);
}

Node* inorderSuccessor(Node* root) {
    root = root->right;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete(Node* root, int target) {
    if (root == NULL) {
        return root;
    }
    if (target < root->data) {
        root->left = delete(root->left, target);
    }
    else if (target > root->data) {
        root->right = delete(root->right, target);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            Node *temp = inorderSuccessor(root);
            root->data = temp->data;
            root->right = delete(root->right, root->data);
        }
    }
    return rotate(root);
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    root = delete(root, 5);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
