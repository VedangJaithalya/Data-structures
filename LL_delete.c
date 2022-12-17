#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void create();
void display();
void Delete_beg();
void Delete_end();
void Delete_pos();

struct NODE
{
    int data;
    struct NODE *link;
};
typedef struct NODE node;
node *start=NULL;
void create()
{
    int c;
    node *new,*curr;
    start=(node *) malloc(sizeof(node));
    curr=start;
    printf("Enter element\n");
    scanf("%d",&start->data);
    while(1)
    {
        printf("Do you want to add another element(Y/N)\n");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *) malloc(sizeof(node));
            printf("Enter element\n");
            scanf("%d",&new->data);
            curr->link = new;
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}
void Delete_beg()
{
    node *temp;
    if (start == NULL)
    {
        printf("\nLinked lis is empty\n");
        return;
    }
    temp = start;
    start = start->link;
    free(temp);
}
void Delete_end()
{
    node *temp, *prev, *next;
    if (start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if (start->link == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
    prev = start;
    next = start->link;

    while (next->link != NULL)
    {
        prev = next;
        next = next->link;
    }
    prev->link = NULL;
    free(next);
    return;
}
void Delete_pos()
{
    int el;
    node *temp, *prev, *next;
    if (start == NULL)
    {
        printf("\nLinked list is empty\n");
        return;
    }
    printf("\nEnter element to be deleted\n");
    scanf("%d", &el);
    if (start->data = el)
    {
        temp=start;
        start=start->link;
        free(temp);
        printf("\nDeleted is %d\n", start->data);
        return;
    }
    prev = start;
    next = start->link;

    while (next->data != el && next != NULL)
    {
        prev = next;
        next = next->link;
    }

    if (next->data == el)
    {
        printf("\nDeleted is %d\n", next->data);
        prev->link = next->link;
        free(next);
        return;
    }
    printf("\nElement Not found\n");
}
void display(){
    node *temp;
    if(start==NULL){
        printf("Linked list is empty\n");
        return;
    }
    temp=start;
    printf("\nLIST\n");
    while(temp!= NULL)
    {
        printf("\n%d\t",temp->data);
        temp=temp->link;
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create LL\t2.Delete at Beg\t3.Delete at end\t4.Delete at position \t5.Display \t6.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;

        case 2:
            Delete_beg();
            break;
        case 3:
            Delete_end();
            break;
        case 4:
            Delete_pos();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
