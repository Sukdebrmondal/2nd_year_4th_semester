// without DAC
#include<stdio.h>
int max(int arr[],int n){
    int i,m;
    m = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }

    }
    return m;
}

int min(int arr[],int n){
    int i,m;
    m = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<m){
            m=arr[i];
        }

    }
    return m;
}


int main(){
    int n;
    printf("Enter the size of element: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Print the elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    // int arr[6]={23,32,100,33,45,8};
    int max_element = max(arr,n);
    printf("\n");
    printf("The max element is:%d",max_element);
    printf("\n");
    int min_element = min(arr,n);
    printf("The min element is:%d",min_element);
}

// with DAC

#include <stdio.h>

void min_max(int arr[], int i, int j, int *min, int *max)
{
    if (i == j)
    {
        *min = *max = arr[i];
        return;
    }

    else if (i == j - 1)
    {
        if (arr[i] < arr[j])
        {
            *min = arr[i];
            *max = arr[j];
        }
        else
        {
            *min = arr[j];
            *max = arr[i];
        }
        return;
    }

    else
    {
        int mid = (i + j) / 2;
        int min1, max1, min2, max2;

        min_max(arr, i, mid, &min1, &max1);
        min_max(arr, mid + 1, j, &min2, &max2);

        if (min1 < min2)
        {
            *min = min1;
        }
        else
        {
            *min = min2;
        }
        if (max1 > max2)
        {
            *max = max1;
        }
        else
        {
            *max = max2;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The elements is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    int min, max;
    min_max(arr, 0, n - 1, &min, &max);

    printf("\nThe minimum value is: %d\n", min);
    printf("The maximum value is: %d\n", max);

    return 0;
}