#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void swap(int * a,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[],int size,int index){
    int left = index*2;
    int right = index*2+1;
    int largest = index;
    if(left <= size && arr[largest] < arr[left] ){
        largest = left;
    }
    if(right <= size && arr[largest] < arr[right] ){
        largest = right;
    }
    if(largest != index){
        swap(&arr[largest],&arr[index]);
        heapify(arr,size,largest);
    }
    else{
        return;
    }
}
int main(){
    int arr[6] = {-1,50,52,53,54,55};
    int size = 5;
    for(int i = ceil(size/2);i>0;i--){
        heapify(arr,size,i);
    }
    for(int i = 1;i<=size;i++){
        printf("%d ",arr[i]);
    }
}