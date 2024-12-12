#include <stdio.h>
int main()
{
    int A[] = {1, 12, 31, 99, 110};

    int B[] = {7, 9, 10, 11, 12, 17};
    int C[10];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < 5 && j < 6)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            k++;
            i++;
        }
        else
        {
            C[k] = B[j];
            k++;
            j++;
        }
    }
    while (i >= 5 && j < 6)
    {
        C[k] = B[j];
        k++;
        j++;
    }
    while (j >= 6 && i < 5)
    {
        C[k] = A[i];
        k++;
        i++;
    }

    for (int i = 0; i < 11; i++)
    {
        printf("%d ", C[i]);
    }
}