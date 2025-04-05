#include<stdio.h>
int patition(int arr[],int low,int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
    int temp=0;
        if(arr[j]<pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=pivot;
    arr[high]=temp;
    return i;

}

void quick_sort(int arr[],int low, int high){
    if(low < high){
        int pivot_index = patition(arr,low,high);
        quick_sort(arr,low,pivot_index-1);
        quick_sort(arr,pivot_index+1,high);
    }
}

int main(){
    // int arr[] = {4,61,8,10,9};
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the unsorted array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quick_sort(arr,0,n-1);

    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}








