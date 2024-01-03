// // array
#include<stdio.h>
//enqueue is adding , dequeue is delete

#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(rear==N-1){
        printf("Oveflow");
    }
    else if(front==-1 && rear ==-1){ //if the queue is empty then front and rear will the same
        front=rear=0;
        queue[rear]=x;
    }
    else{ //if the queue already has an element and needs to add the next element
        rear++; // suppose the first few elemnts are empty , enqueue will not add as rear has reached it's mazimun so instead we use (rear+1)%N
        queue[rear]=x;
    }
}

void dequeue( ){
    if(front==-1 && rear==-1){ //the queue is empty and no elem can be deleted
        printf("Undeflow");
    }
    else if(front==rear){ // there is only one element and both front and rear point at it
        front=rear=-1; //condition inputed for empty queue
    }
    else{
        //printf("Element %d is dequeued\n",queue[x]);
        front++; // the dequeued elemnt is printed and the front is incremented , because the First element is what gets deleted and next tha front
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Empty queue");
    }
    else{
        printf("The Updated queue is:\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
}
void peek(){ //used to print the first element
    if(front==-1 && rear==-1){
        printf("Empty Queue");
    }
    else{
        printf("%d",queue[front]);
    }
}

int main(){
     int data;
    printf("Enter the elements");
    for(int i=0;i<5;i++){
        scanf("%d",&data);
        enqueue(data);
    }
    // enqueue(1);
    // enqueue(2);
    // enqueue(3); 
    // enqueue(4);
    // enqueue(5);
    // dequeue(1); // why we're giving parameter when we know the first element is what will be deleted
    // display();
    printf("peek value:");
    peek();
    printf("\n");
    dequeue( );
    printf("Queue is:\n");
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
    
}

// linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct queue *create() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

struct node *newNode(int x) { // creates a new node
    struct node *createNode = (struct node *)malloc(sizeof(struct node));
    createNode->data = x;
    createNode->next = NULL;
    return createNode;
}

void enqueue(struct queue *q, int x) {
    struct node *temp = newNode(x);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

int isEmpty(struct queue *q) {
    return q->front == NULL;
}

void printQueue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue *q = create();

    int choice, element;

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(q, element);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printf("Queue: ");
                printQueue(q);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}