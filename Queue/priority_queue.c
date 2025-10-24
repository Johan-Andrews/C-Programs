#include <stdio.h>
#include <stdlib.h>
void heapify(int heap[],int i,int n)
{
    int l,r,largest,temp;
    
        l=2*i;
        r=(2*i)+1;
        if(l<=n && heap[l]>heap[i] )
        {
            largest=l;
        }
        else{
            largest=i;
        }
        if(r<=n && heap[r]>heap[largest])
        {
            largest=r;
        }
        if(largest!=i)
        {
            temp=heap[largest];
            heap[largest]=heap[i];
            heap[i]=temp;
            heapify(heap,largest,n);
        }    
}
void insert(int heap[],int elem,int n)
{
    int i;
    heap[n+1]=elem;
    i=n+1;
    while(i>1 && elem>heap[i/2])
    {
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=elem;
}
void delete(int heap[],int n)
{
    int temp,elem;
    temp=heap[1];
    heap[1]=heap[n];
    n=n-1;
    heapify(heap,1,n);
}
void display(int heap[],int n)
{
    int i;
    printf("The Queue is :");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",heap[i]);
    }
    printf("\n");
}
int main()
{
    int i,n,elem,op,heap[50];
    printf("Enter the no of elements you want to insert: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&elem);
        heap[i]=elem;
    }
    display(heap,n);
    for(i=n/2;i>0;i--)
    {
    heapify(heap,i,n);
    }
    printf("The priority queue is:\n");
    display(heap,n);
    printf("Enter the num to the corresponding operation:\n1:Insert elements into the queue\n2:Delete an element from the queue\n3:Display the Queue\n4:Exit\n");
    while(1)
    {
        printf("Enter the operation: ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:printf("Enter the element you want to insert: ");
                    scanf("%d",&elem);
                    insert(heap,elem,n);
                    n+=1;
                    display(heap,n);
                    break;
            case 2:delete(heap,n);
                    n-=1;
                    display(heap,n);
                    break;
            case 3:display(heap,n);
                    break;
            case 4:return 0;
                    break;
            default: return 0;
        }

    }

}