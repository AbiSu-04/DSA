#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* getnode(int value)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=value;
    p->next=NULL;
    return p;
}
struct graph
{
    int vertices;
    struct node** adjList;
};
struct graph* getgraph(int v)
{
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->vertices=v;
    g->adjList=(struct node**)malloc((v+1)*sizeof(struct node*));
    int i;
    for(i=0;i<=v;i++)
    {
        g->adjList[i]=NULL;
    }
    return g;
}
void addedge(struct graph* g,int src,int des)
{
    struct node* newnode=getnode(des);
    newnode->next=g->adjList[src];
    g->adjList[src]=newnode;
}
void display(struct graph* g)
{
    if(g==NULL)
    {
        printf("Empty graph");
        return;
    }
    int i,v=g->vertices;
    for(i=1;i<=v;i++)
    {
        struct node* current=g->adjList[i];
        printf("\nVertex %d:",i);
        printf("\nAdjacent vertices: %d",i);
        while(current!=NULL)
        {
            printf("->%d",current->data);
            current=current->next;
        }
    }
}
int empty(int front,int rear)
{
    return (front==-1 && rear==-1);
}
int full(int front,int rear,int MAX)
{
    return (front==0 && rear==MAX-1);
}
void enqueue(int* arr,int MAX,int* front,int* rear,int value)
{
    if(full(*front,*rear,MAX))
    {
        printf("\nQueue Overflow");
        return;
    }
    if(empty(*front,*rear))
    {
        (*front)++;
        (*rear)++;
        arr[*rear]=value;
        return;
    }
    (*rear)++;
    arr[*rear]=value;
}
int dequeue(int* arr,int* front,int* rear,int MAX)
{
    if(empty(*front,*rear))
    {
        printf("\nQueue Underflow");
        return -1;
    }
    int value=arr[*front];
    if(*front==*rear)
    {
        (*front)=-1;
        (*rear)=-1;
        return value;
    }
    (*front)++;
    return value;
}
void DFS(struct graph* g,int start,int* visited,int* dfs,int* index)
{
    struct node* adj=g->adjList[start];
    struct node* temp=adj;
    visited[start]=1;
    dfs[(*index)++]=start;
    while(temp!=NULL)
    {
        int adjvertex=temp->data;
        if(visited[adjvertex]==0)
        {
            DFS(g,adjvertex,visited,dfs,index);
        }
        temp=temp->next;
    }
}
int main()
{
    int i,j,v,e,src,des,start;
    printf("Enter no of vertices:");
    scanf("%d",&v);
    struct graph* g=getgraph(v);
    printf("Enter no of edges:");
    scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("Enter source:");
        scanf("%d",&src);
        printf("Enter destination:");
        scanf("%d",&des);
        addedge(g,src,des);
    }
    display(g);
    int* dfs=(int*)malloc((v)*sizeof(int));
    printf("\nEnter start vertex:");
    scanf("%d",&start);
    int* visited=(int*)malloc((v+1)*sizeof(int));
    for(i=0;i<=v;i++)
        visited[i]=0;
    int index=0;
    DFS(g,start,visited,dfs,&index);
    printf("\nDFS Traversal:");
    for(i=0;i<index;i++)
    {
        printf("%3d",dfs[i]);
    }
}



