#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head;

struct node *create() {
    struct node *p;
    p=(struct node *) malloc (sizeof(struct node *));
    printf("Enter data of node: ");
    scanf("%u",&p->data);
    p->next = NULL;
    return p;
}

int main() {
    struct node *ptr;
    ptr=create();
    printf(create());
}