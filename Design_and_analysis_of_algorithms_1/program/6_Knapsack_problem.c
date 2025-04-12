
// Algorithm for 0/1 Knapsack Problem using Dynamic Programming
// Input the number of items (n).
// This tells how many items are available to choose from.

// Input the maximum weight capacity of the knapsack (w).
// This is the maximum weight the knapsack can hold.

// Input the profit of each item and store them in an array p[n].
// This tells how much profit you get from each item.

// Input the weight of each item and store them in an array v[n].
// This tells how much each item weighs.

// Create a 2D array dp[n+1][w+1] to store the maximum profit at each subproblem.

// dp[i][j] will represent the maximum profit you can get using the first i items and with capacity j.

// Initialize the first row and first column of the dp table to 0.

// This means when either 0 items or 0 capacity is available, the profit is 0.

// Fill the dp table using the following logic:

// For each item from 1 to n:

// For each capacity from 1 to w:

// If the weight of the current item is less than or equal to the current capacity:

// Calculate the profit if you include the item.

// Calculate the profit if you exclude the item.

// Take the maximum of the two and store in dp[i][j].

// If the weight of the item is more than the current capacity:

// You cannot include the item, so take the value from the previous row dp[i-1][j].

// Print the items that are included in the knapsack (in reverse):

// Start from the last cell dp[n][w].

// If the value is different from the cell above (dp[i][j] != dp[i-1][j]), it means the item was included.

// Print that item and reduce the remaining capacity by the weight of the item.

// Print the maximum profit, which is stored in dp[n][w]







#include <stdio.h>

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of the knapsack: ");
    scanf("%d", &capacity);

    int profit[100], weight[100];
    float ratio[100];

    printf("Enter profit of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = (float) profit[i] / weight[i];
    }

    // big to small
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                //ratio part
                float tempR = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempR;

                // profit part
                int tempP = profit[i];
                profit[i] = profit[j];
                profit[j] = tempP;

                //weight part
                int tempW = weight[i];
                weight[i] = weight[j];
                weight[j] = tempW;
            }
        }
    }

    int remaining = capacity;
    float totalProfit = 0;

    printf("\nItems taken in the knapsack:\n");
    for (int i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            // full
            printf("Item %d: 100%% [Profit: %d, Weight: %d]\n", i + 1, profit[i], weight[i]);
            totalProfit += profit[i];
            remaining -= weight[i];
        } else {
            // others
            float fraction = (float) remaining / weight[i];
            printf("Item %d: %.2f%% [Profit: %d, Weight: %d]\n", i + 1, fraction * 100, profit[i], weight[i]);
            totalProfit += profit[i] * fraction;
            break;
        }
    }

    printf("\n The Maximum Profit: %.2f\n", totalProfit);

    return 0;
}


// output 
// Enter number of items: 4
// Enter capacity of the knapsack: 60
// Enter profit of each item:
// 280 100 120 120
// Enter weight of each item:
// 40 10 20 24

// Items taken in the knapsack:
// Item 1: 100% [Profit: 100, Weight: 10]
// Item 2: 100% [Profit: 280, Weight: 40]
// Item 3: 50.00% [Profit: 120, Weight: 20]

//  The Maximum Profit: 440.00