// 3.b) modify and implement Strassen's Matrix Multiplication algorithm so that it works with non-square matrices as well.(dd -> different dimention)

#include <stdio.h>
#include <math.h>

// Function to add two matrices
void add(int size, int arr_a[size][size], int arr_b[size][size], int res[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            res[i][j] = arr_a[i][j] + arr_b[i][j];
        }
    }
}

// Function to subtract two matrices
void sub(int size, int arr_a[size][size], int arr_b[size][size], int res[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            res[i][j] = arr_a[i][j] - arr_b[i][j];
        }
    }
}

// Strassen's Matrix Multiplication function
void strassen(int size, int arr_a[size][size], int arr_b[size][size], int res[size][size])
{
    if (size == 1)
    {
        res[0][0] = arr_a[0][0] * arr_b[0][0]; // Base case
        return;
    }
    else
    {
        int resize = size / 2;

        // Dividing matrices into sub-matrices
        int a11[resize][resize], a12[resize][resize];
        int a21[resize][resize], a22[resize][resize];
        int b11[resize][resize], b12[resize][resize];
        int b21[resize][resize], b22[resize][resize];

        for (int i = 0; i < resize; i++)
        {
            for (int j = 0; j < resize; j++)
            {
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
        int res11[resize][resize], res12[resize][resize];
        int res21[resize][resize], res22[resize][resize];
        int m1[resize][resize], m2[resize][resize], m3[resize][resize], m4[resize][resize], m5[resize][resize], m6[resize][resize], m7[resize][resize];
        int temp1[resize][resize], temp2[resize][resize];

        // Computing the 7 Strassen products
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

        // Computing final result sub-matrices
        add(resize, m1, m4, temp1);
        sub(resize, temp1, m5, temp2);
        add(resize, temp2, m7, res11);

        add(resize, m3, m5, res12);

        add(resize, m2, m4, res21);

        sub(resize, m1, m2, temp1);
        add(resize, temp1, m3, temp2);
        add(resize, temp2, m6, res22);

        // Combining results into final matrix
        for (int i = 0; i < resize; i++)
        {
            for (int j = 0; j < resize; j++)
            {
                res[i][j] = res11[i][j];
                res[i][j + resize] = res12[i][j];
                res[i + resize][j] = res21[i][j];
                res[i + resize][j + resize] = res22[i][j];
            }
        }
    }
}

// Function to print a matrix
void print_arr(int size, int arr[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to find next power of 2 for padding
int cov(int size)
{
    for (int i = 0;; i++)
    {
        if (pow(2, i) >= size)
        {
            return pow(2, i);
        }
    }
}

// Function to find the maximum of three numbers
int find_max(int a1, int a2, int b2)
{
    return (a1 > a2) ? ((a1 > b2) ? a1 : b2) : ((a2 > b2) ? a2 : b2);
}

int main()
{
    // Input matrix dimensions
    printf("enter the dimention of the first matrix a x b:\n");
    int a1, a2;
    scanf("%d %d", &a1, &a2);
    printf("enter the dimention of the second matrix a x b:\n");
    int b1, b2;
    scanf("%d %d", &b1, &b2);

    if (a2 == b1)
    { // Check if multiplication is possible
        int size = find_max(a1, a2, b2);
        int new_size = cov(size);

        int arr_a[new_size][new_size];
        int arr_b[new_size][new_size];

        // Initializing matrices with zeros
        for (int i = 0; i < new_size; i++)
        {
            for (int j = 0; j < new_size; j++)
            {
                arr_a[i][j] = 0;
                arr_b[i][j] = 0;
            }
        }

        // Input first matrix
        printf("enter the elements of the first matrix: \n");
        for (int i = 0; i < a1; i++)
        {
            for (int j = 0; j < a2; j++)
            {
                scanf("%d", &arr_a[i][j]);
            }
        }

        printf("enter the elements of the second matrix: \n");
        for (int i = 0; i < b1; i++)
        {
            for (int j = 0; j < b2; j++)
            {
                scanf("%d", &arr_b[i][j]);
            }
        }

        int arr_res[new_size][new_size];
        strassen(new_size, arr_a, arr_b, arr_res);
        printf("multiplication of two matrices is:\n");
        print_arr(new_size, arr_res);
    }
    else
    {
        printf("multiplication can not be done!!");
    }
}

/*
output

enter the dimention of the first matrix a x b:
3 4
enter the dimention of the second matrix a x b:
4 5
enter the elements of the first matrix:
23 45 32 67
12 21 34 21
87 45 36 1
enter the elements of the second matrix:
98 23 11 26 45
23 18 46 27 82
32 46 28 45 28
98 46 28 64 35
multiplication of two matrices is:
10879   5893    5095    7541    7966    0       0       0
4805    3184    2638    3753    3949    0       0       0
10811   4513    4063    5161    8648    0       0       0
0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0

enter the dimention of the first matrix a x b:
4 5
enter the dimention of the second matrix a x b:
6 7
multiplication can not be done!!
*/