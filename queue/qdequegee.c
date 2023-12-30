// #include<stdio.h>
// #include<stdlib.h>
// void insert_right(int *arr,int *front,int *rear,int data,int len)
// {
//     if(*front==-1&&*rear==-1){
//         *front=*front+1;
//         *rear=*rear+1;
//         arr[*rear]=data;
//         return;
//     }
//     if((*front==0&&*rear==len-1)||(*front==*rear+1)){
//         printf("oveflow");
//         return;
//     }
//     if(*rear==len-1&&*front!=0){
//         arr[0]=data;
//         *rear=0;
//         *front=0;
//     }
//     /*if(*front==*rear){
//         arr[*rear]=0;
//         *front=0;
//         *rear=0;
//         return;
//     }*/
//     *rear=*rear+1;
//     arr[*rear]=data;
//     return;
// }
// void insert_left(int *arr,int *front,int *rear,int data,int len){
//     if(*front==-1&&*rear==-1){
//         *front=*front+1;
//         *rear=*rear+1;
//         arr[*front]=data;
//         return;
//     }
//     if(*front==0){
//         *front=len-1;
//         arr[*front]=data;
//         return;
//     }
//     if((*front==0&&*rear==len-1)||(*front==*rear+1)){
//         printf("oveflow");
//         return;
//     }
//     *front=*front-1;
//     arr[*front]=data;
//     return;
// }
// void delete_right(int *arr,int *front,int *rear){
//     if(*front==-1&&*rear==-1){
//         printf("underflow");
//         return;
//     }
//     if(*front==*rear){
//         arr[*rear]=0;
//         *rear=-1;
//         *front=-1;
//         return;
//     }
//     arr[*rear]=0;
//     *rear=*rear-1;
//     return;
// }
// void delete_left(int *arr,int *front,int *rear){
//     if(*front==-1&&*rear==-1){
//         printf("underflow");
//         return;
//     }
//     if(*front==*rear){
//         arr[*rear]=0;
//         *rear=-1;
//         *front=-1;
//         return;
//     }
//     arr[*front]=0;
//     *front=*front+1;
//     return;
// }
// int main(){
//     int data,len,c;
//     printf("enter length of array:");
//     scanf("%d",&len);
//     int r=-1,f=-1;
//     int *arr=(int *)calloc(len,sizeof(int));
//     int *front=&f,*rear=&r;
//     printf("enter 1 to insert at right,enter 2 to insert at left,enter 3 to delete at right ,4 to delete at left,-1 to exit");
//     printf("\nEnter choice:");
//     scanf("%d",&c);
//     while(1){
//         if(c==1){
//             printf("enter data:");
//             scanf("%d",&data);
//             insert_right(arr,front,rear,data,len);
//             printf("Enter choice:");
//             scanf("%d",&c);

//         }
//         if(c==2){
//             printf("enter data:");
//             scanf("%d",&data);
//             insert_left(arr,front,rear,data,len);
//             printf("Enter choice:");
//             scanf("%d",&c);
//         }
//         if(c==3){
//             delete_right(arr,front,rear);
//             printf("Enter choice:");
//             scanf("%d",&c);

//         }
//         if(c==4){
//             delete_left(arr,front,rear);
//             printf("Enter choice:");
//             scanf("%d",&c);
//         }
//         if(c==-1){
//             break;
//         }
//     }
//     for(int i=0;i<len;i++){
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *getnode(int data){
    struct  node *p=(struct node *)malloc(sizeof (struct node));
    p->data=data;
    p->next=NULL;
    return p;
}
struct node *insert_right(struct node *start,int data){
    struct node *current=start,*new;
    new=getnode(data);
    if(start==NULL){
        start=new;
        return start;
    }
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=new;
    return start;
}
struct node *insert_left(struct node *start,int data){
    struct node *current=start,*new;
    new=getnode(data);
    if(start==NULL){
        start=new;
        return start;
    }
        // If the linked list is not empty, update the new node's next pointer to point to the current start

    new->next=start;
    start=new;// Update the start pointer to the new node

    return start;

}
struct node *delete_right(struct node *start){
    struct node *new,*current=start;
    if(start==NULL){
        printf("underflow");
        return start;
    }
    if(start->next==NULL){
        start=NULL;
        return start;
    }
     while(current->next->next!=NULL){
        current=current->next;
       }
    current->next=NULL;
    return start;
}
struct node *delete_left(struct node *start){
    if(start==NULL){
        printf("underflow");
        return start;
    }
    if(start->next==NULL){
        start=NULL;
        return start;
    }
    start=start->next;//If there is more than one node in the list, the function updates the start pointer to point to the second node in the list (the one pointed to by the next pointer of the current start node). This effectively removes the first node from the list.


    return start;
}
int main(){
    int c,data;
    struct node *start=NULL;
    printf("enter 1 to insert at right,2 to insert at left,3 to delete at right,4 to delete at right,-1 to exit:");
    printf("\nEnter choice:");
    scanf("%d",&c);
    while(1){
        if(c==1){
            printf("enter data:");
            scanf("%d",&data);
            start=insert_right(start,data);
            printf("Enter choice:");
            scanf("%d",&c);

        }
        if(c==2){
            printf("enter data:");
            scanf("%d",&data);
            start=insert_left(start,data);
            printf("Enter choice:");
            scanf("%d",&c);
        }
        if(c==3){
            start=delete_right(start);
            printf("Enter choice:");
            scanf("%d",&c);

        }
        if(c==4){
            start=delete_left(start);
            printf("Enter choice:");
            scanf("%d",&c);
        }
        if(c==-1){
            break;
        }
    }
    for(struct node *i=start;i!=NULL;i=i->next){
        printf("%d ",i->data);
    }
}
