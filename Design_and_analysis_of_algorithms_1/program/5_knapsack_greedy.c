// 5) write a c program to implement fractional knapsack problem using greedy method.

#include<stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort function to sort items based on profit-to-weight ratio
void quick(int a, int b, int arr[a][b], int st_in, int en_in)
{
    if (st_in < en_in)
    {
        int pivot = arr[2][en_in]; // Choosing the last element as pivot
        int index = st_in - 1;   // Pointer for the smaller element

        // Partitioning the array based on profit-to-weight ratio
        for (int i = st_in; i < en_in; i++)
        {
            if (arr[2][i] >= pivot) // If current element has higher or equal ratio
            {
                index++;
                swap(&arr[0][i], &arr[0][index]); // Swap profits
                swap(&arr[1][i], &arr[1][index]); // Swap weights
                swap(&arr[2][i], &arr[2][index]); // Swap ratios
            }
        }
        index++;
        swap(&arr[0][index], &arr[0][en_in]); // Swap pivot profit to correct position
        swap(&arr[1][index], &arr[1][en_in]); // Swap pivot weight to correct position
        swap(&arr[2][index], &arr[2][en_in]); // Swap pivot ratio to correct position

        // Recursively sorting left and right subarrays
        quick(a, b, arr, st_in, index - 1);
        quick(a, b, arr, index + 1, en_in);
    }
}

// Function to print items in a structured format
void print_items(int a, int b, int arr[a][b]){
    for(int i = 0; i < a; i++){
        if(i == 0){
            printf("profit:\t");
        }
        else if(i == 1){
            printf("weight:\t");
        }
        else{
            printf("ratio:\t");
        }
        for(int j = 0; j < b; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int a = 3, b; // a represents profit, weight, and ratio; b represents the number of items
    
    printf("Enter the number of items:\n");
    scanf("%d", &b);
    
    int arr[a][b]; // 2D array to store profit, weight, and ratio
    
    printf("Enter profit along with item weight:\n");
    for(int i = 0; i < b; i++){
        printf("profit: ");
        scanf("%d", &arr[0][i]);
        printf("weight: ");
        scanf("%d", &arr[1][i]);
        arr[2][i] = arr[0][i] / arr[1][i]; // Calculate profit-to-weight ratio
    }
    
    printf("Before sorting the items by profit ratio:\n");
    print_items(a, b, arr);
    
    printf("After sorting the items by profit ratio:\n");
    quick(a, b, arr, 0, b - 1);
    print_items(a, b, arr);
    
    int taken[2][b]; // Array to store selected items

    printf("Enter knapsack capacity: \n");
    int knapsack_cap;
    scanf("%d", &knapsack_cap);

    int w = 0; // Total weight of selected items
    int p = 0; // Total profit of selected items
    int i = 0;

    // Selecting items based on profit-to-weight ratio
    for(i; i < b; i++){
        if(w + arr[1][i] <= knapsack_cap){ // If item can be fully taken
            w += arr[1][i];
            taken[1][i] = arr[1][i]; // Store weight
            p += arr[0][i];
            taken[0][i] = arr[0][i]; // Store profit
        }
        else{ // Take a fraction of the item if capacity is exceeded
            int w_rest = (knapsack_cap - w);
            taken[1][i] = w_rest;
            int p_rest = arr[2][i] * w_rest;
            taken[0][i] = p_rest;
            w += w_rest;
            p += p_rest;
            break;
        }
    }
    
    // Printing selected items
    printf("list of taken items: \n");
    for(int j = 0; j < 2; j++){
        if(j == 0){
            printf("profit:\t");
        }
        else{
            printf("weight:\t");
        }
        for(int k = 0; k <= i; k++){
            printf("%d\t", taken[j][k]);
        }
        printf("\n");
    }
    printf("\n");

    printf("total %d items were taken\nand profit is %d", w, p);
}