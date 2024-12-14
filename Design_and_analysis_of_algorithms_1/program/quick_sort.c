#include<stdio.h>
int patition(int arr[],int low,int high){
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
    int temp=0;
        if(arr[j]<pivot){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=arr[pivot];
    arr[high]=temp;
    return i;

}

void quick_sort(int arr[],int low, int high){
    if(low<high){
        int pivot_index = patition(arr,low,high);
        quick_sort(arr,low,pivot_index-1);
        quick_sort(arr,pivot_index+1,high);
    }
}

int main(){
    int arr[] = {4,2,1,8,9};
    quick_sort(arr,0,4);

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}