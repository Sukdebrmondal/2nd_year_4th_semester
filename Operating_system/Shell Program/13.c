//  Write a program in C to implement SJF.

#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int arr_index[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j],&arr[j+1]);
                swap(&arr_index[j],&arr_index[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int p;
    int time = 0;
    printf("enter the no of process: ");
    scanf("%d",&p);
    int pr_arr[p];
    int waiting[p];
    int turn_around[p];
    for(int i = 0;i<p;i++){
        printf("enter the burst time for the process %d: ",i+1);
        scanf("%d",&pr_arr[i]);
    }


    int arr_index[p];
    for(int i = 0;i<p;i++){
        arr_index[i] = i;
    }
    bubbleSort(pr_arr,arr_index,p);

    for(int i = 0;i<p;i++){
        waiting[i] = time;
        time+=pr_arr[i];
        turn_around[i] = time;
    }

    float av_time = 0;
    float turn_time = 0;

    printf("\n");
    for(int i = 0;i<p;i++){
        av_time+=waiting[i];
    }
    av_time = av_time/p;


    for(int i = 0;i<p;i++){
        turn_time+=turn_around[i];
    }
    turn_time = turn_time/p;

    printf("process \t burst time \t waiting time \t turn around time\n");
    for(int i = 0;i<p;i++){
        printf("P%d \t\t %d \t\t %d \t\t %d \n",arr_index[i]+1,pr_arr[i],waiting[i],turn_around[i]);
    }
    printf("\n");
    printf("the average waiting time: %.2f ms\n",av_time);
    printf("the average turn around time: %.2f ms\n",turn_time);
}