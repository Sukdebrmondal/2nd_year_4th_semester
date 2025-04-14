#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int main(){
    int n,value;
    node *head=NULL, *temp=NULL, *new_node=NULL;

    printf("enter the no of nodes: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
       new_node=(node *)malloc(sizeof(node));

        if(new_node == NULL){
            printf("Memory Allocation is failed!");
            return 1;
        }
    
    printf("Enter the data for node %d: ",i+1);
    scanf("%d",&value);
    new_node->data=value;
    new_node->next=NULL;

    if(head==NULL){
        head=new_node;
        temp=head;
    }
    else{
        temp->next=new_node;
        temp=new_node;
    }
}

    printf("the linked list are: ");
    temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;

}