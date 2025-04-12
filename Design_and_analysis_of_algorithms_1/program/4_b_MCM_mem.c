// 4.b) MCM problem using top down approach of dynamic programming (memorization).

#include <stdio.h>
#define N 100

int dp[N][N]; // Memoization table for storing results of subproblems
int split[N][N]; // Table to store split indices for optimal parenthesization

// Function to find the minimum number of multiplications required
int mcm(int arr[], int i, int j)
{
    if (i == j)
        return 0; // Only one matrix, no multiplication needed
    if (dp[i][j] != -1)
        return dp[i][j]; // Use stored result if available
    
    int min = 1000000; // Initialize with a large value
    for (int k = i; k < j; k++)
    {
        // Recursively calculate minimum cost of multiplying matrices
        int sum = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        
        if (sum < min)
        {
            min = sum;
            split[i][j] = k; // Store the split index for optimal solution
        }
    }
    return dp[i][j] = min; // Store the computed value in memoization table
}

// Function to print optimal parenthesization
void parenthesis(int i, int j)
{
    if (i == j)
    {
        printf(" A%d ", i);
    }
    else
    {
        printf("(");
        parenthesis(i, split[i][j]);     // Print left part
        parenthesis(split[i][j] + 1, j); // Print right part
        printf(")");
    }
}

int main()
{
    printf("Enter the number of matrices:\n");
    printf("As example, enter 2 for matrices with dimensions (1,2,3)like that \n");
    
    int size;
    scanf("%d", &size); // Read number of matrices

    int arr[size + 1]; // Array to store matrix dimensions

    // Read dimensions of matrices
    printf("Enter the matrix dimensions: \n");
    for (int i = 0; i <= size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Display input matrix dimensions
    printf("Input matrix dimensions are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("(%d %d) ", arr[i], arr[i + 1]);
    }
    printf("\n");

    // Initialize memoization table with -1
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }

    // Compute minimum multiplication cost
    int min_multiplications = mcm(arr, 1, size);

    printf("Minimum number of multiplications is: %d\n", min_multiplications);
    printf("Optimal parenthesization is: ");
    parenthesis(1, size);
    printf("\n");
    return 0;
}


/*
Enter the number of matrices:
As example, enter 2 for matrices with dimensions (1,2,3)like that
4
Enter the matrix dimensions:
5 4 3 2 1
Input matrix dimensions are:
(5 4) (4 3) (3 2) (2 1)
Minimum number of multiplications is: 38
Optimal parenthesization is: ( A1 ( A2 ( A3  A4 )))


Enter the number of matrices:
As example, enter 2 for matrices with dimensions (1,2,3)like that
5
Enter the matrix dimensions:
64 23 21 12 8 3
Input matrix dimensions are:
(64 23) (23 21) (21 12) (12 8) (8 3)
Minimum number of multiplications is: 6909
Optimal parenthesization is: ( A1 ( A2 ( A3 ( A4  A5 ))))

*/