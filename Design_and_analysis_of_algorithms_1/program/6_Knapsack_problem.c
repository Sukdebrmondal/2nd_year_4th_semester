
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