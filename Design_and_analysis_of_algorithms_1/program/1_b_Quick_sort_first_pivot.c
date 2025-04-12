#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[low];
    arr[low] = arr[i - 1];
    arr[i - 1] = temp;

    return i - 1;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// output->
// Enter the size of array: 4
// Enter the unsorted array: 5 1 6 3
// The sorted array is: 1 3 5 6

// Enter the size of array: 6
// Enter the unsorted array: 65 23 1 8 56 78
// The sorted array is: 1 8 23 56 65 78