// // circular singely
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

    printf("\nCircular Linked List:");
    do {
        i += 1;
        printf("\nNode %d: Data:%d Next node address:%p", i, current->data, (void*)current->next);
        printf(" Current address: %p", (void*)current);
        current = current->next;
    } while (current != start);
}

void insertatbeg(struct node** start, struct node* newnode) {
    if (*start == NULL) {
        *start = newnode;
        newnode->next = *start;
    } else {
        struct node* current = *start;
        while (current->next != *start) {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = *start;
        *start = newnode;
    }
}

void insertatend(struct node** start, struct node* newnode) {
    if (*start == NULL) {
        *start = newnode;
        newnode->next = *start;
    } else {
        struct node* current = *start;
        while (current->next != *start) {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = *start;
    }
}

struct node* search(struct node* start, int value) {
    struct node* current = start;

    if (current == NULL) {
        return NULL; // Empty list, nothing to search
    }

    do {
        if (value == current->data) {
            return current;
        }
        current = current->next;
    } while (current != start);

    return NULL; // Value not found
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
}

void insertbefore(struct node** start, struct node* address, struct node* newnode) {
    struct node* current = *start;

    if (*start == address) {
        while (current->next != *start) {
            current = current->next;
        }
        newnode->next = *start;
        current->next = newnode;
        *start = newnode;
    } else {
        while (current->next != address) {
            current = current->next;
        }
        newnode->next = address;
        current->next = newnode;
    }
}

void delete1stnode(struct node** start) {
    if (*start == NULL) {
        printf("\nEmpty list");
    } else {
        printf("\nLinked list before deletion:");
        display(*start);
        struct node* temp = *start;
        struct node* current = *start;
        while (current->next != *start) {
            current = current->next;
        }
        current->next = (*start)->next;
        *start = (*start)->next;
        free(temp);
        printf("\nLinked list after deleting 1st node:");
        display(*start);
    }
}

void deletelastnode(struct node** start) {
    if (*start == NULL) {
        printf("\nEmpty list");
    } else {
        printf("\nLinked list before deletion:");
        display(*start);

        struct node* current = *start;
        struct node* prev = NULL;

        while (current->next != *start) {
            prev = current;
            current = current->next;
        }

        prev->next = *start;
        free(current);

        printf("\nLinked list after deleting last node:");
        display(*start);
    }
}

void deleteafter(struct node** start, struct node* node) {
    struct node* temp = node->next;

    if (temp == *start) {
        printf("\nNo node to delete after that");
        return;
    }

    printf("\nLinked list before deletion:");
    display(*start);

    node->next = temp->next;
    free(temp);

    printf("\nLinked list after deleting the node:");
    display(*start);
}

void deletebefore(struct node** start, struct node* address, struct node* pre) {
    if (*start == address) {
        printf("\nNo node to delete before that");
        return;
    }

    printf("\nLinked list before deletion:");
    display(*start);

    if (*start == pre) {
        struct node* temp = *start;
        *start = address;
        free(temp);
    } else {
        struct node* current = *start;
        while (current->next != pre) {
            current = current->next;
        }
        current->next = address;
        free(pre);
    }

    printf("\nLinked list after deleting the node:");
    display(*start);
}

int main() {
    struct node* start = NULL;
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
                    struct node* current = getnode(x);
                    insertatbeg(&start, current);
                }
                break;

            case 2:
                printf("Enter no of nodes to be inserted at the end:");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter data:");
                    scanf("%d", &x);
                    struct node* current = getnode(x);
                    insertatend(&start, current);
                }
                break;

            case 3:
                if (start != NULL) {
                    printf("\nEnter the data to be searched:");
                    scanf("%d", &y);
                    struct node* address = search(start, y);
                    if (address == NULL)
                        printf("Element is not in the list");
                    else
                        printf("Data:%d Next node address:%p", address->data, (void*)address->next);
                } else {
                    printf("Empty list");
                }
                break;

            case 4:
                if (start != NULL) {
                    printf("\nEnter data of node after which new node has to be inserted:");
                    scanf("%d", &y);
                    struct node* address = search(start, y);
                    if (address == NULL)
                        printf("Element is not in the list");
                    else {
                        printf("Enter the data to be inserted:");
                        scanf("%d", &d);
                        struct node* newnode = getnode(d);
                        insertafter(address, newnode);
                    }
                }
                break;

            case 5:
                if (start != NULL) {
                    printf("\nEnter the data of the node before which a node has to be inserted:");
                    scanf("%d", &y);
                    struct node* address = search(start, y);
                    if (address == NULL)
                        printf("Element is not in the list");
                    else {
                        printf("\nEnter the data to be inserted:");
                        scanf("%d", &d);
                        struct node* newnode = getnode(d);
                        if (previous(start, address) == NULL) {
                            insertatbeg(&start, newnode);
                        } else {
                            struct node* pre = previous(start, address);
                            insertbefore(&start, address, newnode);
                        }
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
                    struct node* address = search(start, y);
                    if (address == NULL)
                        printf("Element is not in the list");
                    else {
                        deleteafter(&start, address);
                    }
                }
                break;

            case 9:
                if (start != NULL) {
                    printf("\nEnter data of node before which node has to be deleted:");
                    scanf("%d", &y);
                    struct node* address = search(start, y);
                    if (address == NULL)
                        printf("Element is not in the list");
                    else {
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


//circular double
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
    int i = 1;
    if (start == NULL) {
        printf("Empty list");
        return;
    }
    printf("\nStart address:%d", start);
    printf("\nNode %d: \nData:%d ", i, current->data);
    printf("Previous node address:%d ", current->prev);
    printf("Next node address:%d", current->next);
    current = current->next;
    while (current != start) {
        i++;
        printf("\nNode %d: \nData:%d ", i, current->data);
        printf("Previous node address:%d ", current->prev);
        printf("Next node address:%d", current->next);
        current = current->next;
    }
}

void insertatbeg(struct node** start, struct node* newnode) {
    struct node* current = *start;
    if (*start == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
        *start = newnode;
        return;
    }
    newnode->next = *start;
    newnode->prev = (*start)->prev;
    (*start)->prev->next = newnode;
    (*start)->prev = newnode;
    *start = newnode;
}

void insertatend(struct node** start, struct node* newnode) {
    struct node* current = *start;
    if (*start == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
        *start = newnode;
        return;
    }
    newnode->next = *start;
    newnode->prev = (*start)->prev;
    (*start)->prev->next = newnode;
    (*start)->prev = newnode;
}

struct node* search(struct node* start, int value) {
    if (value == start->data)
        return start;
    struct node* current = start->next;
    while (current != start) {
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
    node->next->prev = newnode;
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
    printf("\nLinked list before deletion:");
    display(*start);
    if ((*start)->next == *start) {
        free(*start);
        *start = NULL;
    } else {
        temp = *start;
        temp->next->prev = (*start)->prev;
        (*start)->prev->next = temp->next;
        *start = (*start)->next;
        free(temp);
    }
    printf("\nLinked list after deleting 1st node:");
    display(*start);
}

void deletelastnode(struct node** start) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nLinked list before deletion:");
    display(*start);
    if ((*start)->next == *start) {
        free(*start);
        *start = NULL;
    } else {
        temp = (*start)->prev;
        temp->prev->next = *start;
        (*start)->prev = temp->prev;
        free(temp);
    }
    printf("\nLinked list after deleting last node:");
    display(*start);
}

void deleteafter(struct node** start, struct node* node) {
    printf("\nLinked list before deletion:");
    display(*start);
    if (node == *start && (*start)->next == *start) {
        free(*start);
        *start = NULL;
    } else {
        struct node* temp = node->next;
        node->next = temp->next;
        if (temp == *start) {
            *start = temp->next;
        } else {
            temp->next->prev = node;
        }
        free(temp);
    }
    printf("\nLinked list after deleting the node:");
    display(*start);
}

void deletebefore(struct node** start, struct node* address, struct node* pre) {
    struct node* temp;
    printf("\nLinked list before deletion:");
    display(*start);
    if (address == *start && (*start)->prev == *start) {
        free(*start);
        *start = NULL;
    } else if (pre == *start) {
        address->next = (*start)->next;
        address->prev = address;
        free(pre);
        *start = address;
    } else {
        address->prev = pre->prev;
        pre->prev->next = address;
        free(pre);
    }
    printf("\nLinked list after deleting the node:");
    display(*start);
}

void printforw(struct node* start) {
    struct node* current = start;
    int i = 1;
    if (start == NULL) {
        printf("Empty list");
        return;
    }
    printf("\nStart address:%d", start);
    printf("\nNode %d: \nData:%d ", i, current->data);
    printf("Previous node address:%d ", current->prev);
    printf("Next node address:%d", current->next);
    current = current->next;
    while (current != start) {
        i++;
        printf("\nNode %d: \nData:%d ", i, current->data);
        printf("Previous node address:%d ", current->prev);
        printf("Next node address:%d", current->next);
        current = current->next;
    }
}

void printback(struct node* start) {
    struct node* current = start;
    if (start == NULL) {
        printf("\nEmpty list");
        return;
    }

    int i = 1;
    while (current->next != start) {
        i++;
        current = current->next;
    }
    printf("\nStart address:%d", start);
    while (current != start) {
        printf("\nNode %d: \nData: %d ", i, current->data);
        printf("Previous node address: %d ", current->prev);
        printf("Next node address: %d", current->next);
        current = current->prev;
        i--;
    }
    printf("\nNode %d: \nData:%d ", i, current->data);
    printf("Previous node address:%d ", current->prev);
    printf("Next node address:%d", current->next);
}

int main() {
    struct node* start, * current, * temp;
    start = NULL;
    int n, i, x, y, d, choice;
    printf("1.Insert as 1st node\n");
    printf("2.Insert as last node\n");
    printf("3.Search node\n");
    printf("4.Insert after node\n");
    printf("5.Insert before node\n");
    printf("6.Delete 1st node\n");
    printf("7.Delete last node\n");
    printf("8.Delete after node\n");
    printf("9.Delete before node\n");
    printf("10.Display linked list forward\n");
    printf("11.Display linked list backward\n");
    printf("12.End\n");
    do {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter no of nodes to be inserted at beginning:");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter data:");
                    scanf("%d", &x);
                    current = getnode(x);
                    insertatbeg(&start, current);
                }
                break;
            case 2:
                printf("Enter no of nodes to be inserted at end:");
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
                        printf("\nData:%d ", address->data);
                        printf("Previous node address:%d ", address->prev);
                        printf("Next node address:%d", address->next);
                    }
                }
                break;
            case 4:
                if (start != NULL) {
                    printf("\nEnter data of node after which new node has to be inserted :");
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
                    printf("\nEnter the data of the node before which node has to be inserted :");
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
                printforw(start);
                break;
            case 11:
                printback(start);
                break;
            default:
                printf("End");
        }
    } while (choice != 12);
    return 0;
}
