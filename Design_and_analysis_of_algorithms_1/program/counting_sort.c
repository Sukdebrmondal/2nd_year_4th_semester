#include<stdio.h>
 int countsort(int arr[],int n)
 {
    int max = arr[0],min = arr[0],i;
    for(i=1;i<n;i++){
        if(max < arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    
    int r = max-min+1;
    int count[r];
    int b[n];

    for(i = 0;i<r;i++){
        count[i] = 0;
    }
    for(i=0;i<n;i++){
        count[arr[i]-min]++;
    }
    for(i=1;i<r;i++){
        count[i] += count[i-1];
    }
    for(i=n-1;i>=0;i--){
        b[count[arr[i]-min]-1] = arr[i];
    }

    for(i=0;i<n;i++){
        arr[i] = b[i];
    }

    return arr[i];
 }

 void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
 }

 void main(){
    int n;
    printf("Enter the size of unsorted array:");
    scanf("%d",&n);

    int a[n],output[n];

    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    countsort(a,n);
    printf("The sorted array is: ");
    printarray(a,n);
    
 }