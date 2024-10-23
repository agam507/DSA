#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head;
void main () {
    struct Node *node1= (struct Node *) malloc (sizeof (struct Node *));
    struct Node *node2= (struct Node *) malloc (sizeof (struct Node *));
    struct Node *node3= (struct Node *) malloc (sizeof (struct Node *));
    struct Node *node4= (struct Node *) malloc (sizeof (struct Node *));
    head = node1;
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node1->data=30;
    node2->data=40;
    node3->data=50;
    node4->data=60;

    printf("data of ist node %d \n", node1->data);
    printf("address of next node %u \n", node1->next);
    printf("data of next node %d \n", node2->data);
    printf("address of next node %u \n", node2->next);
    printf("data of next node %d \n", node3->data);
    printf("address of next node %u \n", node3->next);
    printf("data of next node %d \n", node4->data);
    printf("address of next node %u \n", node4->next);
    printf("address in head %u \n",head);
    printf("address in nodel %u \n", node1);
    printf("address in node2 %u \n", node2);
    printf("address in node3 %u\n", node3);
    printf("address in node4 %u \n", node4);
}