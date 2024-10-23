#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next , *prev;
}*head;

struct node *createnode()
{
    struct node *p;
    p = (struct node *) malloc (sizeof(int));
    printf("Enter Data: ");
    scanf("%d",&p->data);
    p->next = NULL;
    p->prev = NULL;
    return p;
}

struct node *create_cdll (struct node *head, int n)
{
    struct node *last, *newnode;
    while (n>0) 
    {
        if (head == NULL) // if is empty
        {
            head = createnode();
            head->next=head;
            head->prev=head;
        }
        else
        {
            last = head->prev; // point to last node
            newnode = createnode();
            last->next=newnode;
            newnode->prev=last;
            newnode->next=head;
            head->prev=newnode;
        }
        n--;
    }
        return head;
}
void print(struct node *h)
{   struct node *last,*temp;
  temp=h;
      last=head->prev;
    do
    {
        printf("prev=%u  %d  next=%u\n",temp->prev,temp->data,temp->next);
        temp=temp->next;
    } while (temp!=head);
   
}

int main()
{
    
    head=create_cdll(head,3);
    print(head);
}
