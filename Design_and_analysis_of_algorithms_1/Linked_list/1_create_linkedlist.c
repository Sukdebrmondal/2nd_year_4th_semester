#include<stdio.h>
#include<stdlib.h>
// define structure of a node
typedef struct node{
    int data; //data field
    struct node *next;    //point the next node
}node;


int main(){

    //ceate first node as a head of the linked list
    node *first=(node *)malloc(sizeof(node));
    //assign data
    first->data=10;
    // 2nd node
    node *second=(node *)malloc(sizeof(node));
    second->data=20;
    // create 3rd node
    node *third=(node *)malloc(sizeof(node));
    third->data=30;

    //link the linked list
    first->next=second;
    second->next=third;
    third->next=NULL;

    printf("the linked list are: ");
    node *temp=first;
    while (temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}