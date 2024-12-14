#include<stdio.h>
void countingsort(int arr[],int n){
    int max = arr[0],min = arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    int range = max-min+1;
    int count[range];
    int brr[n];
    for(int i=0;i<range;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        count[arr[i]-min]++;
    }

    for(int i=1;i<range;i++){
        count[i] += count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        brr[count[arr[i]-min]-1]=arr[i];
        count[arr[i]-min]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=brr[i];
    }

}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    // if(n<=0){
    //     printf("Invalid size!");
    //     return 1;
    // }
    // int arr[n], output[n];
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    countingsort(arr,n);
    printf("The sorted array is: ");
    printarr(arr,n);

}