#include <stdio.h>

int binary_search(int arr[], int low, int high, int ele)
{
    if (low == high)
    {
        if (arr[low] == ele)
        {
            return low;
        }
        else
        {
            return -1;
        }
    }

    else
    {
        int mid = (low + high) / 2;
        if (arr[mid] == ele)
        {
            return mid;
        }

        else if (ele < arr[mid])
        {

            return binary_search(arr, low, mid - 1, ele);
        }
        else
        {
            return binary_search(arr, mid + 1, high, ele);
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of element: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Print the elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int low=0;
    // printf("\nEnter the lower index: ");
    // scanf("%d", &low);

    int high=n-1;
    // printf("\nEnter the higher: ");
    // scanf("%d", &high);

    int e;
    printf("\nEnter the element: ");
    scanf("%d", &e);

   int res =  binary_search(arr, low, high, e);
   printf("The index is :%d",res+1);

}