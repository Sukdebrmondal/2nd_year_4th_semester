#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;



int isEmpty()
{
    return front > rear;
}

int isFull()
{
    return rear == MAX - 1;
}


void dispaly()
{
    if (isEmpty())
    {
        printf("Empty1");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void Enqueue(int x)
{
    if (!isFull())
    {
        rear++;
        queue[rear] = x;
        dispaly();
    }

    else
    {
        printf("The Queue is Full!");
    }
}

void DeQueue()
{
    if (!isEmpty())
    {
        front++;
        dispaly();
    }
    else
    {
        printf("The Queue is empty!");
    }
}

int getfront()
{
    if (!isEmpty())
    {
        return queue[front];
    }
    else
    {
        return -1;
    }
}



int main()
{

    int choice, x;
    printf("1.Enqueue  \n2.Dequeue  \n3.Front Element  \n4.Display ");
    while (1)
    {
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter The Elements: ");
            scanf("%d", &x);
            Enqueue(x);
            break;

        case 2:
            DeQueue();
            break;
        case 3:
            x = getfront();
            if (x != -1)
            {
                printf("The Front Elements is: %d ", x);
            }
            else
            {
                printf("Empty");
            }
            break;
        case 4:
            dispaly();
            break;
        case 5:
            exit(1);
        default:
            printf("Enter valid Number!");
            break;
        }
    }
}