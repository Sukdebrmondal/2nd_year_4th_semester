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