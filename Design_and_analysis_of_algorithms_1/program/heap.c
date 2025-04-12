#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int heap_arr[100];
int size = 0;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int i){
    size++;
    int index = size;
    heap_arr[index] = i;
    while(index > 1){
        int parent = ceil(index/2);
        if(heap_arr[parent] < heap_arr[index]){
            swap(&heap_arr[parent],&heap_arr[index]);
        }
        index = parent;
    }
}

int delete(){
    if(size <= 1){
        printf("can not delete \n");
    }
    else{

        int del = heap_arr[1];
        swap(&heap_arr[1],&heap_arr[size]);
        size--;
        int i = 1;
        while(i < size){
            int left = i*2;
            int right = i*2 + 1;
            if(heap_arr[left] > heap_arr[i] && left < size){
                swap(&heap_arr[left],&heap_arr[i]);
                i = left;
            }
            else if(heap_arr[right] > heap_arr[i] && right < size){
                swap(&heap_arr[right],&heap_arr[i]);
                i = right;
            }
            else{
                break;
            }
        }
        return del;
    }
}

void print_heap(){
    for(int i = 1;i<=size;i++){
        printf("%d ",heap_arr[i]);
    }
    printf("\n");
}

int main(){
    
    insert(50);
    insert(55);
    insert(53);
    insert(52);
    insert(54);
    print_heap();
    delete();
    print_heap();
    delete();
    print_heap();
    delete();
    print_heap();
    delete();
    print_heap();
    delete();

}


