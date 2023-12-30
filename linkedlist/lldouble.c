#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* getnode(int value) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = value;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void display(struct node* start) {
    struct node* current = start;
    int i = 0;
    
    if (start == NULL) {
        printf("Empty list");
        return;
    }
    
    while (current != NULL) {
        i++;
        printf("\nNode %d:\nData: %d ", i, current->data);
        printf("Previous node address: %d ", current->prev);
        printf("Next node address: %d ", current->next);
        printf("current address: %d ", current);
        current = current->next;
    }
}

void insertatend(struct node** start, struct node* newnode) {
    struct node* current = *start;  // why mention this
    
    if (*start == NULL) {
        *start = newnode;
        return;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newnode;
    newnode->prev = current;
}

void insertatbeg(struct node** start, struct node* newnode) {
    if (*start == NULL) {
        *start = newnode;
        return;
    }
    
    newnode->next = *start;
    (*start)->prev = newnode;
    *start = newnode;
}

struct node* search(struct node* start, int value) {
    struct node* current = start;
    
    while (current != NULL) {
        if (value == current->data) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

struct node* previous(struct node* start, struct node* address) {
    if (start == address) {
        return NULL;
    } else {
        struct node* current = start;
        while (current->next != address) {
            current = current->next;
        }
        return current;
    }
}

void insertafter(struct node* node, struct node* newnode) {
    newnode->next = node->next;
    node->next = newnode;
    newnode->prev = node;
}

void insertbefore(struct node* pre, struct node* newnode, struct node* address) {
    address->prev = newnode;
    pre->next = newnode;
    newnode->next = address;
    newnode->prev = pre;
}

void delete1stnode(struct node** start) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    if (*start == NULL) {
        printf("Empty list");
    } else {
        printf("\nLinked list before deletion:");
        display(*start);
        temp = *start;
        *start = (*start)->next;
        free(temp);
        printf("\nLinked list after deleting 1st node:");
        display(*start);
    }
}

void deletelastnode(struct node** start) {
    if (*start == NULL) {
        printf("Empty list");
    } else {
        printf("\nLinked list before deletion:");
        display(*start);
        
        if ((*start)->next == NULL) {
            *start = NULL;
            free(*start);
        } else {
            struct node* current = *start;
            while (current->next->next != NULL)
                current = current->next;
            current->next = NULL;
            free(current->next);
        }
        
        printf("\nLinked list after deleting last node:");
        display(*start);
    }
}

void deleteafter(struct node** start, struct node* node) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    if (node->next == NULL) {
        printf("No node to delete after that");
        return;
    } else {
        printf("\nLinked list before deletion:");
        display(*start);
        temp = node->next;
        node->next = temp->next;
       //temp->next->prev = node;
        free(temp);
    }
    
    printf("\nLinked list after deleting the node:");
    display(*start);
}

void deletebefore(struct node** start, struct node* address, struct node* pre) {
    struct node* temp;
    
    if (*start == address) {
        printf("No node to delete before that");
        return;
    }
    
    printf("\nLinked list before deletion:");
    display(*start);
    
    if (*start == pre) {
        temp = *start;
        *start = address;
        address->prev = NULL;
        free(temp);
    } else {
        struct node* current = *start;
        while (current->next != pre) {
            current = current->next;
        }
        current->next = address;
        pre->next = current;
        free(pre);
    }
    
    printf("\nLinked list after deleting the node:");
    display(*start);
}

int main() {
    struct node* start, * current, * temp;
    start = NULL;
    int n, i, x, y, d, choice;
    
    printf("1. Insert as 1st node\n");
    printf("2. Insert as last node\n");
    printf("3. Search node\n");
    printf("4. Insert after node\n");
    printf("5. Insert before node\n");
    printf("6. Delete 1st node\n");
    printf("7. Delete last node\n");
    printf("8. Delete after node\n");
    printf("9. Delete before node\n");
    printf("10. Display linked list\n");
    printf("11. End\n");
    
    do {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of nodes to be inserted at the beginning:");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter data:");
                    scanf("%d", &x);
                    current = getnode(x);
                    insertatbeg(&start, current);
                }
                break;
                
            case 2:
                printf("Enter the number of nodes to be inserted at the end:");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter data:");
                    scanf("%d", &x);
                    current = getnode(x);
                    insertatend(&start, current);
                }
                break;
                
            case 3:
                if (start != NULL) {
                    printf("\nEnter the data to be searched:");
                    scanf("%d", &y);
                    if (search(start, y) == NULL)
                        printf("Element is not in the list");
                    else {
                        struct node* address = search(start, y);
                        printf("\nData: %d ", address->data);
                        printf("Previous node address: %d ", address->prev);
                        printf("Next node address: %d", address->next);
                    }
                }
                break;
                
            case 4:
                if (start != NULL) {
                    printf("\nEnter the data of the node after which a new node has to be inserted:");
                    scanf("%d", &y);
                    if (search(start, y) == NULL)
                        printf("Element is not in the list");
                    else {
                        struct node* address = search(start, y);
                        printf("Enter the data to be inserted:");
                        scanf("%d", &d);
                        struct node* newnode = getnode(d);
                        insertafter(address, newnode);
                        display(start);
                    }
                }
                break;
                
            case 5:
                if (start != NULL) {
                    printf("\nEnter the data of the node before which a node has to be inserted:");
                    scanf("%d", &y);
                    if (search(start, y) == NULL)
                        printf("Element is not in the list");
                    else {
                        struct node* address = search(start, y);
                        printf("Enter the data to be inserted:");
                        scanf("%d", &d);
                        struct node* newnode = getnode(d);
                        if (previous(start, address) == NULL) {
                            insertatbeg(&start, newnode);
                        } else {
                            struct node* pre = previous(start, address);
                            insertbefore(pre, newnode, address);
                        }
                        display(start);
                    }
                }
                break;
                
            case 6:
                delete1stnode(&start);
                break;
                
            case 7:
                deletelastnode(&start);
                break;
                
            case 8:
                if (start != NULL) {
                    printf("\nEnter the data of the node after which a node has to be deleted:");
                    scanf("%d", &y);
                    if (search(start, y) == NULL)
                        printf("Element is not in the list");
                    else {
                        struct node* address = search(start, y);
                        deleteafter(&start, address);
                    }
                }
                break;
                
            case 9:
                if (start != NULL) {
                    printf("\nEnter the data of the node before which a node has to be deleted:");
                    scanf("%d", &y);
                    if (search(start, y) == NULL)
                        printf("Element is not in the list");
                    else {
                        struct node* address = search(start, y);
                        if (previous(start, address) == NULL) {
                            printf("No node to delete before that");
                        } else {
                            struct node* pre = previous(start, address);
                            deletebefore(&start, address, pre);
                        }
                    }
                }
                break;
                
            case 10:
                display(start);
                break;
                
            default:
                printf("End");
        }
    } while (choice != 11);
    
    return 0;
}