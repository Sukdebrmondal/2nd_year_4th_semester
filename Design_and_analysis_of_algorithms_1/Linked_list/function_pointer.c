#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{
    int n1 = 5;
    int n2 = 10;
    printf("n1= %d,n2= %d", n1, n2);
    printf("\n");
    swap(&n1, &n2);
    printf("n1= %d,n2= %d", n1, n2);
}