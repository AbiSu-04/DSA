#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* getnode(int data) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

void display(struct node* start) {
    struct node* current = start;
    int i = 0;
    
    if (current == NULL) {
        printf("Empty list");
        return;
    }
    
    while (current != NULL) {
        i += 1;
        printf("\nNode %d: Data:%d Next node address:%d", i, current->data, current->next);
        printf("current address: %d", current);
        current = current->next;
    }
}

void insertatbeg(struct node** start, struct node* newnode) {
    newnode->next = *start;
    *start = newnode;
}

void insertatend(struct node** start, struct node* newnode) {
    if (*start == NULL)
        *start = newnode;
    else {
        struct node* current = *start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
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
    newnode->next = node->next;  // basically in 1 2 3 i need to delete after 1 , so am changing 1 next address to 2 oda next address, next add of 1 is 3 oda add
    node->next = newnode;
}

void insertbefore(struct node* pre, struct node* newnode, struct node* address) {
    newnode->next = address; //1 // since it is before linking new node next add as the add of before what am linking ( if 2 3 5 and adding 4, the 4 oda next add points to 5)
    pre->next = newnode; //2 // that it if  2 3 5  and inserting 4 am putting 3 oda next add as 4 oda add (as prev is prev of 5 , my desired)
} // if i change order of 1 and 2 also it works

void delete1stnode(struct node** start) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    if (*start == NULL) {
        printf("\nEmpty list");
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
    if (*start == NULL)
        printf("\nEmpty list");
    else {
        printf("\nLinked list before deletion:");
        display(*start);
        
        if ((*start)->next == NULL) {
            *start = NULL;
            free(*start);
        } else {
            struct node* current = *start;
            while (current->next->next != NULL)
                current = current->next; //outside loop thana irukannum?
                free(current->next);
            current->next = NULL;
            
        }
        
        printf("\nLinked list after deleting last node:");
        display(*start);
    }
}

void deleteafter(struct node** start, struct node* node) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nLinked list before deletion:");
    display(*start);
    
    if (node->next == NULL) {
        printf("\nNo node to delete after that");
        return;
    } else {
        temp = node->next;
        node->next = temp->next; // basically in 1 2 3 i need to delete after 1 , so am changing 1 next address to 2 oda next address, next add of 1 is 3 oda add
        free(temp);
    }
    
    printf("\nLinked list after deleting the node:");
    display(*start);
}

void deletebefore(struct node** start, struct node* address, struct node* pre) {
    struct node* temp;
    printf("\nLinked list before deletion:");
    display(*start);
    
    if (*start == address) {
        printf("\nNo node to delete before that"); // check if needed

        return;
    }
    
    if (*start == pre) { // checking if the head node is pre  if so store in temp variable
        temp = *start;
        *start = address;
        free(temp);
    } else {
        struct node* current = *start; // start refers to starting node addsess 4 3 2 1 ( 4 start, 2 adddress), loop stars from start
        while (current->next != pre) {
            current = current->next; // to change current address , until 4 (prev ku prev)
        }
        current->next = address; // so the current is 4 , instaed of address of 3 , we are adding address of two as next address)
        free(pre); // pre is the address before 2 (i.e address of 3)
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
                printf("Enter no of nodes to be inserted at the beginning:");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter data:");
                    scanf("%d", &x);
                    current = getnode(x);
                    insertatbeg(&start, current);
                }
                break;
                
            case 2:
                printf("Enter no of nodes to be inserted at the end:");
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
                        printf("Data:%d Next node address:%d", address->data, address->next);
                    }
                }
                break;
                
            case 4:
                if (start != NULL) {
                    printf("\nEnter data of node after which new node has to be inserted:");
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
                        printf("\nEnter the data to be inserted:");
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
                    printf("\nEnter data of node after which node has to be deleted:");
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
                    printf("\nEnter data of node before which node has to be deleted:");
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
}