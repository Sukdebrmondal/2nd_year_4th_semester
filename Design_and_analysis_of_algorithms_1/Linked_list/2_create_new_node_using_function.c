#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create_node(int data)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode ->data=data;
    newnode->next=NULL;
}

int main(){
    node *first=create_node(10);
    first->next=create_node(20);
    first->next->next=create_node(30);
    first->next->next->next=create_node(40);

    printf("The linked list are: ");
    node *temp=first;
    while (temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    return 0;
}