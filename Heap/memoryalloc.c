#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct node
{
        int ID;
        int mark;
        int size;
        struct node* Rlink;
        struct node* Llink;
};

int ID=0;
struct node* current=NULL;

void Display(struct node* Head)
{
        struct node* ptr;
        if(Head->Rlink!=NULL)
        {
                ptr=Head->Rlink;
                while(ptr!=NULL)
                {
                        if(ptr->ID==-1)
                                printf("[Free | size:%d] -> ",ptr->size);
                        else if(ptr->mark==1)
                                printf("[Id:%d | size:%d | Marked] -> ",ptr->ID,ptr->size);
                        else
                                printf("[Id:%d | size:%d | Unmarked] -> ",ptr->ID,ptr->size);

                        ptr=ptr->Rlink;
                }
        }
        printf("NULL\n");
}

void allocate(int size,struct node* h)
{
        struct node* newnode,*ptr;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->size=size;
        newnode->ID=++ID;
        newnode->mark=0;

        if(current->size>size)
        {
                current->size-=size;
                newnode->Llink=current->Llink;
                newnode->Rlink=current;
                current->Llink=newnode;
                ptr=newnode->Llink;
                ptr->Rlink=newnode;
                printf("Allocated block ID=%d, size=%d\n",ID,size);
        }
        else
        {
                ptr=current;
                while(ptr!=NULL && (ptr->size<size || ptr->ID!=-1))
                {
                        ptr=ptr->Rlink;
                }
                if(ptr==NULL)
                {
                        ID=ID-1;
                        printf("No space left\n");
                        free(newnode);
                }
                else
                {
                        newnode->Llink=ptr->Llink;
                        newnode->Rlink=ptr;
                        ptr->Llink=newnode;
                        ptr->size-=size;
                        ptr=newnode->Llink;
                        ptr->Rlink=newnode;
                        printf("Allocated block ID=%d, size=%d\n",ID,size);

                }
        }
}

int Free(int ID,struct node* h)
{

        struct node* ptr=h->Rlink,*temp,*ptr1,*ptr2;;
        while(ptr!=NULL && ptr->ID!=ID)
                ptr=ptr->Rlink;
        if(ptr==NULL)
        {
                printf("No such ID\n");
                return 0;
        }
        else
        {
                ptr->ID=-1;
                temp=ptr;
                ptr=ptr->Rlink;
                if(ptr->ID==-1)
                {
                        temp->size=temp->size+ptr->size;
                        temp->Rlink=ptr->Rlink;
                        ptr2=ptr->Rlink;
                        if (ptr2!=NULL)
                                ptr2->Llink=temp;
                        free(ptr);
                }

                ptr=temp->Llink;

                if(ptr->ID==-1)
                {
                        temp->size=temp->size+ptr->size;
                        temp->Llink=ptr->Llink;
                        ptr2=ptr->Llink;
                        ptr2->Rlink=temp;
                        free(ptr);
                }
                ptr=temp;
                while(temp->Llink!=NULL)
                {
                        if(temp->ID==-1)
                                break;
                }
                if(temp->Llink==NULL)
                        current=ptr;
                return 1;
        }
}
void  Mark(int ID,struct node* h)
{
        struct node* ptr=h->Rlink,*temp;
        while(ptr!=NULL && ptr->ID!=ID)
                ptr=ptr->Rlink;
        if(ptr==NULL)
                printf("No such ID\n");
        else
        {
                ptr->mark=1;
                printf("Marked block with ID=%d\n",ID);
        }
}
void  collector(struct node* h)
{
        struct node* ptr=h->Rlink,temp;
        int IDs,size;
        while(ptr!=NULL)
        {
                if(ptr->ID!=-1 && ptr->mark==0)
                {
                        IDs=ptr->ID;
                        size=ptr->size;
                        Free(IDs,h);
                        printf("GC:Freed unreachable block ID=%d, size=%d\n",IDs,size);
                }
                else if(ptr->ID!=-1)
                        ptr->mark=0;
                ptr=ptr->Rlink;
        }
}

void main()
{
        struct node *Head,*space;
        int item,n,op;
        Head=(struct node*)malloc(sizeof(struct node));
        space=(struct node*) malloc(sizeof(struct node));
        if(Head==NULL || space==NULL)
                printf("Memory allocation failed\n");
        else
        {
                Head->ID=0;
                Head->Llink=NULL;
                Head->Rlink=space;

                space->Llink=Head;
                space->Rlink=NULL;
                space->ID=-1;
                space->mark=1;
                space->size=974;

                current=space;

                while(1)
                {
                        scanf("%d",&op);
                        if(op==1)
                        {
                                scanf("%d",&item);
                                allocate(item,Head);
                        }
                        else if(op==2)
                        {
                                scanf("%d",&item);
                                if(Free(item,Head))
                                        printf("Freed bloak with ID:%d\n",item);
                        }
                        else if(op==3)
                        {
                                scanf("%d",&item);
                                Mark(item,Head);

                        }
                        else if(op==4)
                        {
                                collector(Head);
                        }
                        else if(op==5)
                                Display(Head);
                        else if(op==6)
                                break;
                }
        }
}
