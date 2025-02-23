#include <stdio.h>
#include <stdio.h>

void merge(int a[], int p, int q, int r)
{
    int range = (r - p + 1);
    int merge[range];
    int s = q + 1;
    int x = 0;
    while (p <= q && s <= r)
    {
        if (a[p] <= a[s])
        {
            merge[x++] = a[p++];
        }
        else
        {
            merge[x++] = a[s++];
        }
    }

    while (p <= q)
    {
        merge[x++] = a[p++];
    }

    while (s <= r)
    {
        merge[x++] = a[s++];
    }

    for (int i = 0, j = p; i < range; i++, j++)
    {
        a[j] = merge[i];
    }
}

void merge_sort(int a[], int p, int r)
{
    if (p >= r)
    {
        return;
    }

    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
}

int main()
{
    // int arr[]={6,9,5,2,8};
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("The elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    merge_sort(a, 0, n - 1);
    printf("The sorted array is :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}