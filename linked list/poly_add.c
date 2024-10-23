#include <stdio.h>
#include<stdlib.h>
struct node
{
    int coff,deg;
    struct node *next;
};
struct node *head1,*head2,*headm;
struct node *create(int n)
{ int i;
    struct node *p,*q,*head;
    if(n!=0)
    {
        p=(struct node *)malloc(sizeof(struct node));
        printf("Enter coff and degree: ");
        scanf("%d %d",&p->coff,&p->deg);
        p->next=NULL;
        head=p;
        for(i=2;i<=n;i++)
        {
            q=(struct node *)malloc(sizeof(struct node));
             printf("Enter coff and degree of next term: ");
            scanf("%d %d",&q->coff,&q->deg);
            q->next=NULL;
            p->next=q;
            p=q;
        }
    
        return head;
    }   
    
}
void print(struct node *h)
{
     if(h==NULL)
     {
         printf("Empty list");
     }
   else
      while(h!=NULL)
       {
        printf(" Coff of  node=%d \t power =%d\n",h->coff,h->deg);
        printf("address of next node=%u\n",h->next);
        h=h->next;
       }
}
struct node *polyadd(struct node *h1,struct node *h2)
{
    struct node *ptr,*headp,*p,*q;
    p=h1;
    q=h2;
    ptr=(struct node *)malloc(sizeof(struct node));
    headp=ptr;
   
    while(p&&q)
    {
        if(p->deg > q->deg)
        {
            ptr->coff=p->coff;
            ptr->deg=p->deg;
            p=p->next;
        }
        else
          {  if(p->deg < q->deg)
             {
            ptr->coff=q->coff;
            ptr->deg=q->deg;
            q=q->next;
            }
            else
            {
                ptr->coff=p->coff+q->coff;
            ptr->deg=p->deg;
            p=p->next;
            q=q->next;
            }
          }
     if(p&&q)
      {
         ptr->next=(struct node *)malloc(sizeof(struct node));
        ptr=ptr->next; 
      } 
 }
 if(p||q)
 {
     while(p!=NULL)
     {
       ptr->next=(struct node *)malloc(sizeof(struct node));
       ptr=ptr->next; 
        ptr->coff=p->coff;
            ptr->deg=p->deg;
            p=p->next;
     }
     while(q!=NULL)
     {
       ptr->next=(struct node *)malloc(sizeof(struct node));
       ptr=ptr->next; 
        ptr->coff=q->coff;
            ptr->deg=q->deg;
            q=q->next;
     }
  }
  
 return headp;
  
}

int main() 
{
    printf("First list\n");
    head1=create(2);
    
    printf("Second list\n");
    head2=create(3);
    
    printf("\nNodes of first list\n");
    print(head1);
    
printf("\nNodes of second list\n");
    print(head2);
    
    headm=polyadd(head1,head2);
    printf("\n---------------------------------\n");
printf("\nList after merging of the two lists:\n");
    print(headm);  
    
    return 0;
}