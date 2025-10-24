#include <stdio.h>
#include <stdlib.h>
int front=-1;
int rear=-1;
int visited=0;
int Queue[100];
int stack[100];
int top=-1;
struct node 
{
    int data;
    struct node* link;
};
// arr[30];
struct node* arr[30];
int visit[30]={-1};
struct node* root=NULL;
struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data; 
    newnode->link = NULL;
    return newnode;
}
void enque(int data)
{
    if(rear==99)
    {
        printf("Queue overflow");
        return;
    }
    if(front==-1)
    {
        front++;
    }
    Queue[++rear]=data;
 
}
int deque()
{
    int temp;
    if(front==-1)
    {
        printf("queue underfole");
        return 0;
    }
    else{
        if(front==rear)
        {
            temp= Queue[front];
            front=-1;
            rear=-1;
            return temp;
        }
        return Queue[front++];
    }
}

void push(int a)
{
    if (top>=99)
        printf("stack overflow");
    else
    {
        top++;
        stack[top]=a;
    }
}
int pop()
{
    if (top==-1)
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        return stack[top--];
    }
    
}
struct node* creategraph(int i)
{
    int nei;
    struct node* graph=NULL;
    struct node* temp;
    printf("Enter the neighbour of %d (enter -1 if no more neigbour):",i);
    scanf("%d",&nei);
    while(nei!=-1)
    {
        if(graph==NULL)
        {
            graph=createnode(nei);
            temp=graph;
        }
        else{
            if(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=createnode(nei);
            temp=temp->link;
        }
        printf("Enter the neighbour of %d (enter -1 if no more neigbour):",i);
        scanf("%d",&nei);
    }
    return graph;

}
void bfs(int n)
{
    struct node* link;
    int node,v,i,f=1,k=0;
    for(i=0;i<30;i++)
    {
        visit[i]=-1;
    }
    printf("Enter where you want to start the bfs: ");
    scanf("%d",&node);
    enque(node);
    visit[k]=node;
    k++;
    while(front!=-1)
    {
        v=deque();
        link=arr[v];
        printf("%d\t",v);
        while(link!=NULL)
        {
            f=1;
            for(i=0;i<30;i++)
            {
                if(visit[i]==link->data)
                {f=0;}
            }
            if(f)
            {
            enque(link->data);
            visit[k]=link->data;
            k++;
            }
            link=link->link; 
        }

    }
    
}
void dfs(int n)
{
    struct node* link;
    int node,v,i,f=1,k=0;
    for(i=0;i<30;i++)
    {
        visit[i]=-1;
    }
    printf("\nEnter where you want to start the dfs: ");
    scanf("%d",&node);
    push(node);
    visit[k]=node;
    k++;
    while(top!=-1)
    {
        v=pop();
        link=arr[v];
        printf("%d\t",v);
        while(link!=NULL)
        {
            f=1;
            for(i=0;i<30;i++)
            {
                if(visit[i]==link->data)
                {f=0;}
            }
            if(f)
            {
            push(link->data);
            visit[k]=link->data;
            k++;
            }
            link=link->link; 
        }

    }
    
}
int main()
{
    int n,i,data;
    struct node* temp;
    printf("enter the no of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        arr[i]=creategraph(i);
    }
    for(i=0;i<n;i++)
    {
        temp=arr[i];
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n");
        
    }
    bfs(n);
    dfs(n);
}
