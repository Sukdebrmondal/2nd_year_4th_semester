// 3.a) write a c program to implement Strassen's Matrix Multiplication algorithm for square matrices using divide and conquer.

#include<stdio.h>
#include<math.h>

// Function to add two matrices
void add(int size, int arr_a[size][size], int arr_b[size][size], int res[size][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            res[i][j] = arr_a[i][j] + arr_b[i][j];
        }
    }
}

// Function to subtract two matrices
void sub(int size, int arr_a[size][size], int arr_b[size][size], int res[size][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            res[i][j] = arr_a[i][j] - arr_b[i][j];
        }
    }
}

// Strassen's matrix multiplication function
void strassen(int size, int arr_a[size][size], int arr_b[size][size], int res[size][size]) {
    if(size == 1) {
        res[0][0] = arr_a[0][0] * arr_b[0][0];
        return;
    }
    else {
        int resize = size / 2;

        // Dividing matrices into 4 submatrices
        int a11[resize][resize], a12[resize][resize], a21[resize][resize], a22[resize][resize];
        int b11[resize][resize], b12[resize][resize], b21[resize][resize], b22[resize][resize];

        for(int i = 0; i < resize; i++) {
            for(int j = 0; j < resize; j++) {
                a11[i][j] = arr_a[i][j];
                b11[i][j] = arr_b[i][j];
                a12[i][j] = arr_a[i][j + resize];
                b12[i][j] = arr_b[i][j + resize];
                a21[i][j] = arr_a[i + resize][j];
                b21[i][j] = arr_b[i + resize][j];
                a22[i][j] = arr_a[i + resize][j + resize];
                b22[i][j] = arr_b[i + resize][j + resize];
            }
        }

        // Intermediate matrices
        int m1[resize][resize], m2[resize][resize], m3[resize][resize], m4[resize][resize], m5[resize][resize], m6[resize][resize], m7[resize][resize];
        int temp1[resize][resize], temp2[resize][resize];

        // Computing the 7 matrix multiplications
        add(resize, a11, a22, temp1);
        add(resize, b11, b22, temp2);
        strassen(resize, temp1, temp2, m1);

        add(resize, a21, a22, temp1);
        strassen(resize, temp1, b11, m2);

        sub(resize, b12, b22, temp1);
        strassen(resize, a11, temp1, m3);

        sub(resize, b21, b11, temp1);
        strassen(resize, a22, temp1, m4);

        add(resize, a11, a12, temp1);
        strassen(resize, temp1, b22, m5);

        sub(resize, a21, a11, temp1);
        add(resize, b11, b12, temp2);
        strassen(resize, temp1, temp2, m6);

        sub(resize, a12, a22, temp1);
        add(resize, b21, b22, temp2);
        strassen(resize, temp1, temp2, m7);

        // Computing final quadrants of result matrix
        int res11[resize][resize], res12[resize][resize], res21[resize][resize], res22[resize][resize];

        add(resize, m1, m4, temp1);
        sub(resize, temp1, m5, temp2);
        add(resize, temp2, m7, res11);

        add(resize, m3, m5, res12);
        add(resize, m2, m4, res21);

        sub(resize, m1, m2, temp1);
        add(resize, temp1, m3, temp2);
        add(resize, temp2, m6, res22);

        // Merging results into final matrix
        for(int i = 0; i < resize; i++) {
            for(int j = 0; j < resize; j++) {
                res[i][j] = res11[i][j];
                res[i][j + resize] = res12[i][j];
                res[i + resize][j] = res21[i][j];
                res[i + resize][j + resize] = res22[i][j];
            }
        }
    }
}

// Function to print a matrix
void print_arr(int size, int arr[size][size]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get the next power of 2 greater than or equal to size
int cov(int size) {
    for(int i = 0;; i++) {
        if(pow(2, i) >= size) {
            return pow(2, i);
        }
    }
}

int main() {
    printf("Enter the dimension of the square matrix n:\n");
    int size;
    scanf("%d", &size);
    int new_size = cov(size);
    int arr_a[new_size][new_size];
    int arr_b[new_size][new_size];

    // Initializing matrices to 0
    for(int i = 0; i < new_size; i++) {
        for(int j = 0; j < new_size; j++) {
            arr_a[i][j] = 0;
            arr_b[i][j] = 0;
        }
    }

    // Input matrices
    printf("Enter the elements of the first matrix:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &arr_a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &arr_b[i][j]);
        }
    }

    int arr_res[new_size][new_size];
    strassen(new_size, arr_a, arr_b, arr_res);
    printf("Multiplication of two matrices is:\n");
    print_arr(new_size, arr_res);
}

// output->
// Enter the dimension of the square matrix n:
// 4
// Enter the elements of the first matrix:
// 4 3 2 1
// 8 7 6 5
// 12 11 10 9
// 16 15 14 13
// Enter the elements of the second matrix:
// 20 19 18 17
// 21 22 23 24
// 28 27 26 25
// 29 30 31 32
// Multiplication of two matrices is:
// 228     226     224     222
// 620     618     616     614
// 1012    1010    1008    1006
// 1404    1402    1400    1398




// Enter the dimension of the square matrix n:
// 2
// Enter the elements of the first matrix:
// 34 23
// 54 87
// Enter the elements of the second matrix:
// 12 15
// 32 73
// Multiplication of two matrices is:
// 1144    2189
// 3432    7161