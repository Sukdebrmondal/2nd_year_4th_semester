#include <stdio.h>
#include <stdlib.h>
struct node *createnewlist(int arr[], int size);

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int arr[] = {10, 20, 30};
    struct node *head = NULL;
    head = createnewlist(arr, 3);
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
        /* code */
    }
}

struct node *createnewlist(int arr[], int size)
{
    struct node *head = NULL, *temp = NULL, *current = NULL;
    for (int i = 0; i < size; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}