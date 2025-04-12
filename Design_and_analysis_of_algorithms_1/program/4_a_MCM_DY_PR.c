// 4.a) write a c program to implement matrix chain multiplication problem using dynamic programming.

#include <stdio.h>
#define a 100  // Define a constant for the max matrix size

// Function to compute the Matrix Chain Multiplication (MCM) cost and split points
void mcm(int n, int arr[], int m[a][a], int s[a][a])
{
    // Initialize the cost of multiplying a single matrix to 0
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    
    // Iterate over chain lengths from 2 to n
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = 1000000; // Initialize to a large value (infinity)
            
            // Try all possible places to split the product
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                
                // Update minimum cost and store the best split point
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print the optimal parenthesization of matrices
void parens(int s[a][a], int i, int j)
{
    if (i == j)
    {
        printf(" A%d ", i); // Print individual matrix
    }
    else
    {
        printf("("); // Print opening parenthesis
        parens(s, i, s[i][j]); // Recursively print left sub-chain
        parens(s, s[i][j] + 1, j); // Recursively print right sub-chain
        printf(")"); // Print closing parenthesis
    }
}

int main()
{
    printf("Enter the number of mattrix:\n");
    printf("as example 2 for (1,2,3) matrix\n");
    
    int size;
    scanf("%d", &size); // Read number of matrices
    
    int arr[size + 1]; // Array to store matrix dimensions
    
    // Read dimensions of matrices
    for(int i = 0; i <= size; i++){
        scanf("%d", &arr[i]);
    }

    // Display input matrix dimensions
    printf("input matrix dimensions are : \n");
    for(int i = 0; i < size; i++){
        printf("(%d %d) ", arr[i], arr[i+1]);
    }
    printf("\n");

    int m[a][a] = {0}; // Cost matrix
    int s[a][a] = {0}; // Split matrix

    // Compute optimal multiplication order and cost
    mcm(size, arr, m, s);

    // Print cost matrix
    printf("The cost matrix is:\n");
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if(i == j || i < j){
                printf("%d\t", m[i][j]);
            }
            else{
                printf("\t");
            }
        }
        printf("\n");
    }
    
    // Print parenthesization matrix
    printf("The parenthesis matrix is:\n");
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if(i < j){
                printf("%d\t", s[i][j]);
            }
            else{
                printf("\t");
            }
        }
        printf("\n");
    }

    // Print the optimal parenthesization sequence
    printf("The optimal solution is\n");
    parens(s, 1, size);
    printf("\n");

    return 0;
}


/*

Enter the number of mattrix:
as example 2 for (1,2,3) matrix

5
5 7 6 3 9 3
input matrix dimensions are :
(5 7) (7 6) (6 3) (3 9) (9 3)
The cost matrix is:
0       210     231     366     357
        0       126     315     261
                0       162     135
                        0       81
                                0
The parenthesis matrix is:
        1       1       3       3
                2       3       2
                        3       3
                                4

The optimal solution is
(( A1 ( A2  A3 ))( A4  A5 ))



Enter the number of mattrix:
as example 2 for (1,2,3) matrix
3
4 2 6 4
input matrix dimensions are :
(4 2) (2 6) (6 4)
The cost matrix is:
0       48      80
        0       48
                0
The parenthesis matrix is:
        1       1
                2

The optimal solution is
( A1 ( A2  A3 ))

*/