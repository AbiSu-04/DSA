// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     int data;
//     struct node *left, *right;
// };

// struct node *getnode(int data) {
//     struct node *p = malloc(sizeof(struct node));
//     p->data = data;
//     p->left = NULL;
//     p->right = NULL;
//     return p;
// }

// void insert(struct node **root, int data) {
//     struct node *newnode = getnode(data);

//     if (*root == NULL) {
//         *root = newnode;
//     } else if (data > (*root)->data) {
//         insert(&((*root)->right), data);
//     } else {
//         insert(&((*root)->left), data);
//     }
// }

// void display(struct node *root) {
//     // inorder traversal
//     if (root != NULL) {
//         display(root->left);
//         printf("%d ", root->data);
//         display(root->right);
//     }
// }

// struct node *search(struct node *parent, struct node *root, int data, int *lr) {
//     if (root == NULL) {
//         return NULL;
//     }

//     if (root->data == data) {
//         return parent;
//     } else if (data > root->data) {
//         *lr = 1;
//         return search(root, root->right, data, lr);
//     } else {
//         *lr = 0;
//         return search(root, root->left, data, lr);
//     }
// }

// int main() {
//     printf("Enter the no of elements:");
//     int elements, lr = 2;
//     scanf("%d", &elements);
//     struct node *root = NULL;

//     for (int i = 0; i < elements; i++) {
//         int data;
//         printf("Enter the data:");
//         scanf("%d", &data);
//         insert(&root, data);
//     }

//     display(root);

//     int dataToSearch = 5;
//     struct node *parent = search(NULL, root, dataToSearch, &lr);

//     if (parent == NULL) {
//         printf("\n%d not found in the tree\n", dataToSearch);
//     } else {
//         if (lr == 0) {
//             printf("\n%d found to the left of %d\n", dataToSearch, parent->data);
//         } else {
//             printf("\n%d found to the right of %d\n", dataToSearch, parent->data);
//         }
//     }

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* getnode(int data) {
    struct node* p = malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void insert(struct node** root, int data) {
    if (*root == NULL) {
        *root = getnode(data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    } else {
        insert(&((*root)->left), data);
    }
}
struct node* successor(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* predecessor(struct node* root) {
    struct node* current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}
void display(struct node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}
struct node* search(struct node* parent, struct node* root, int data, int* side) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return parent;
    } else if (data > root->data) {
        *side = 1;
        return search(root, root->right, data, side);
    } else {
        *side = 0;
        return search(root, root->left, data, side);
    }
}
struct node* deleteNode(struct node* root, int key) {
// no child   
 if (root == NULL) return root;
  //search   
  if (key < root->data)
        root->left = deleteNode(root->left, key);
  // search   
  else if (key > root->data)
        root->right = deleteNode(root->right, key);
   // 1 child 
   else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
   //both child     
        struct node* temp = predecessor(root->left);
        root->right = deleteNode(root->right, temp->data); 
    }
    return root;
}
int main() {
    struct node* root = NULL;
    int elements;
    printf("Enter the number of elements: ");
    scanf("%d", &elements);
    for (int i = 0; i < elements; i++) {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(&root, data);
    }
    printf("Binary Search Tree: ");
    display(root);
    printf("\n");
    int data;
    printf("Enter the data to be deleted: ");
    scanf("%d", &data);
    struct node *rt=deleteNode(root, data);
    printf("BST after deletion: ");
    display(rt);
    printf("\n");
    return 0;
}

// Suc and pred
// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *left,*right;
// };
// struct node *getnode(int data){
//     struct node *p=malloc(sizeof(struct node));
//     p->data=data;
//     p->left=NULL;
//     p->right=NULL;
//     return p;
// }
// /*void insert(struct node **root){
//     for(int i=0;i<elements;i++){
//         int data;
//         printf("Enter the data:");
//         scanf("%d",&data);
//         struct node *newnode=getnode(data);
//         struct node *temp=*root;
//         struct node *parent=*root;
//         int j=0;
//         while(1){
//             if(*temp==NULL){
//                 temp=newnode;
//                 break;
//             }
//             else if((*root)->data<data){
//                 temp=temp->right;
//             }
//             else{
//                 temp=temp->left;
//             }
//         }
//     }
// }*/
// void insert(struct node **root, int data) {
//     struct node *newnode = getnode(data);
    
//     if (*root == NULL) {
//         *root = newnode;
//     } else if (data > (*root)->data) {
//         insert(&((*root)->right), data);
//     } else {
//         insert(&((*root)->left), data);
//     }
// }
// void display(struct node *root){
//     //inorder traversal
//     if(root->left!=NULL){
//         display(root->left);
//     }
//     printf("%d ",root->data);
//     if(root->right!=NULL){
//         display(root->right);
//     }
// }
// struct node *search(struct node *parent, struct node *root, int data, int *lr) {
//     if (root == NULL) {
//         return NULL;
//     }
//     if (root->data == data) {
//         return parent;
//     } else if (data > root->data) {
//         *lr = 1;
//         return search(root, root->right, data, lr);
//     } else {
//         *lr = 0;
//         return search(root, root->left, data, lr);
//     }
// }
// void predecessor(struct node*root){
//     if(root->left!=NULL){
//         root=root->left;
//         while(root->right!=NULL){
//             root=root->right;
//         }
//         printf("predecessor is %d",root->data);
//     }
//     else{
//         printf("No predecessor");
//     }
// }
// void successor(struct node* root) {
//     if (root->right != NULL) {
//         root = root->right;
//         while (root->left != NULL) {
//             root = root->left;
//         }
//         printf("Successor is %d", root->data);
//     }
//     else {
//         printf("No successor");
//     }
// }
// int main() {
//     struct node *root = NULL;
//     int n, data;
//     printf("Enter the number of elements to insert: ");
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         printf("Enter data for element %d: ", i + 1);
//         scanf("%d", &data);
//         insert(&root, data);
//     }
//     printf("BST elements (in-order traversal): ");
//     display(root);
//     printf("\n");
//     int key;
//     printf("Enter the element to find its predecessor and successor: ");
//     scanf("%d", &key);
//     int lr = 0; // Initialize to 0, 0 means the element is the root
//     struct node *parent = search(NULL, root, key, &lr);
//     struct node *element = (lr == 0) ? root : (lr == 1) ? parent->right : parent->left;
//     if (element != NULL) {
//         printf("Predecessor of %d is: ", key);
//         predecessor(element);
//         printf("\n");
//         printf("Successor of %d is: ", key);
//         successor(element);
//         printf("\n");
//     } else {
//         printf("Element not found in the BST.\n");
//     }
//     return 0;
// }

// // Traversal -ll
// #include<stdio.h>
// #include<stdlib.h>
// struct Node {
//     int data;
//     struct Node *left, *right;
// };
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }
// struct Node* insert(struct Node* node, int data) {
//     if (node == NULL) {
//         return createNode(data);
//     }
//     if (data < node->data) {
//         node->left = insert(node->left, data);
//     } else if (data > node->data) {
//         node->right = insert(node->right, data);
//     }
//     return node;
// }
// void inorder(struct Node* root) {
//     if (root != NULL) {
//         inorder(root->left);
//         printf("%d -> ", root->data);
//         inorder(root->right);
//     }
// }
// void preorder(struct Node* root) {
//     if (root != NULL) {
//         printf("%d -> ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }
// void postorder(struct Node* root) {
//     if (root != NULL) {
//         postorder(root->left);
//         postorder(root->right);
//         printf("%d -> ", root->data);
//     }
// }
// int main() {
//     struct Node* root = NULL;
//     int data;
//     printf("Enter the data for the root node: ");
//     scanf("%d", &data);
//     root = insert(root, data);
//     while (1) {
//         printf("Enter data for the node (-1 to stop): ");
//         scanf("%d", &data);
//         if (data == -1) {
//             break;
//         }
//         insert(root, data);
//     }
//     printf("\nInorder Traversal of the Binary Search Tree: ");
//     inorder(root);
//     printf("\n");
//     printf("\nPreorder Traversal of the Binary Search Tree: ");
//     preorder(root);
//     printf("\n");
//     printf("\nPostorder Traversal of the Binary Search Tree: ");
//     postorder(root);
//     printf("\n");
//     return 0;
// }




 