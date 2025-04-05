#include <stdio.h>
#include<stdlib.h>

void multiplication(int R1, int R2, int C1, int C2, int m1[][C1], int m2[][C2])
{
    int res[R1][C2];
    printf("The result is: \n");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < R2; k++)
            {
                res[i][j] += m1[i][k] * m2[k][j];
            }
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int R1, R2, C1, C2;
    printf("Enter the Dimentoins Rows and Columns of 1st matrix: ");
    scanf("%d %d", &R1, &C1);
    int m1[R1][C1];
    printf("Enter the Elements: ");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("The Elements of 1st maxtrix is:\n");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    printf("Enter the Dimentoins Rows and Columns of 2nd matrix: ");
    scanf("%d %d", &R2, &C2);
    int m2[R2][C2];
    printf("Enter the Elements: ");
    for (int i = 0; i < R2; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    printf("The Elements of 2nd matricx is:\n");
    for (int i = 0; i < R2; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    if(C1 != R2){
        printf("Matrix multiplication not apply !");
        printf("if want to apply so you done C1=R2 ");
        exit(1);
    }
    multiplication(R1, R2, C1, C2, m1, m2);
}