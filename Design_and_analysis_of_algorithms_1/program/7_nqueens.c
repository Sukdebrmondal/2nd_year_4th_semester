// // write a c program to implement nqueens problem using backtracking.

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Function to print the board configuration
void board(int x[], int n) {
    printf("solutions are : \n");
    for (int j = 0; j < n; j++) {
        printf(" %d ", x[j]+1);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i] == j) {
                printf(" Q ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at position (k, i)
bool place(int x[], int k, int i) {
    for (int j = 0; j < k; j++) {
        if ((x[j] == i) || (fabs(x[j] - i) == fabs(j - k))) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void nqueen(int x[], int k, int n) {
    for (int i = 0; i < n; i++) {
        if (place(x, k, i)) {
            x[k] = i;
            if (k == n - 1) {
                board(x, n);
                printf("\n");
            } else {
                nqueen(x, k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    int x[n]; // Array to store queen positions
    nqueen(x, 0, n);

    return 0;
}


// output 
// Enter the number of queens: 4
// solutions are :
//  2  4  1  3
//  -  Q  -  -
//  -  -  -  Q
//  Q  -  -  -
//  -  -  Q  -

// solutions are :
//  3  1  4  2
//  -  -  Q  -
//  Q  -  -  -
//  -  -  -  Q
//  -  Q  -  -


// Enter the number of queens: 5
// solutions are :
//  1  3  5  2  4
//  Q  -  -  -  -
//  -  -  Q  -  -
//  -  -  -  -  Q
//  -  Q  -  -  -
//  -  -  -  Q  -

// solutions are :
//  1  4  2  5  3
//  Q  -  -  -  -
//  -  -  -  Q  -
//  -  Q  -  -  -
//  -  -  -  -  Q
//  -  -  Q  -  -

// solutions are :
//  2  4  1  3  5
//  -  Q  -  -  -
//  -  -  -  Q  -
//  Q  -  -  -  -
//  -  -  Q  -  -
//  -  -  -  -  Q

// solutions are :
//  2  5  3  1  4
//  -  Q  -  -  -
//  -  -  -  -  Q
//  -  -  Q  -  -
//  Q  -  -  -  -
//  -  -  -  Q  -

// solutions are :
//  3  1  4  2  5
//  -  -  Q  -  -
//  Q  -  -  -  -
//  -  -  -  Q  -
//  -  Q  -  -  -
//  -  -  -  -  Q

// solutions are :
//  3  5  2  4  1
//  -  -  Q  -  -
//  -  -  -  -  Q
//  -  Q  -  -  -
//  -  -  -  Q  -
//  Q  -  -  -  -

// solutions are :
//  4  1  3  5  2
//  -  -  -  Q  -
//  Q  -  -  -  -
//  -  -  Q  -  -
//  -  -  -  -  Q
//  -  Q  -  -  -

// solutions are :
//  4  2  5  3  1
//  -  -  -  Q  -
//  -  Q  -  -  -
//  -  -  -  -  Q
//  -  -  Q  -  -
//  Q  -  -  -  -

// solutions are :
//  5  2  4  1  3
//  -  -  -  -  Q
//  -  Q  -  -  -
//  -  -  -  Q  -
//  Q  -  -  -  -
//  -  -  Q  -  -

// solutions are :
//  5  3  1  4  2
//  -  -  -  -  Q
//  -  -  Q  -  -
//  Q  -  -  -  -
//  -  -  -  Q  -
//  -  Q  -  -  -
