#include<stdio.h>

void bubbleSort(int arr[], int n){
    for(int i =0 ;i<n;i++){
        for(int j = 1;j<n-i;j++){
        int temp =0;
            if(arr[j-1]>arr[j]){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void selectionsort(int arr[],int n){
    for(int i =0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp =0;
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j] =temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int current_value= arr[i];
        while(arr[j]>current_value && j>=0){
            arr[j-1] = arr[j];
            j--;
        }
        arr[j]=current_value;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}


int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the value of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // printf("The bubble sorted array is: ");
    // bubbleSort(arr, n);
    // printf("\n");
    printf("The selection sorted array is: ");
    selectionsort(arr,n);
    // printf("\n");
    // printf("The insertion sorted array is: ");
    // selectionsort(arr,n);
    
}