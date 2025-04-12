
#include<stdio.h>

void conqueer(int arr[],int si,int mid,int ei){
    int range = (ei-si+1);
    int merge[range];
    int index_1 = si;
    int index_2 = mid+1;
    int x =0;
    while(index_1<=mid && index_2<=ei){
        if(arr[index_1]<=arr[index_2]){
            merge[x] = arr[index_1];
            x++;
            index_1++;
        }
        else{
            merge[x] = arr[index_2];
            x++;
            index_2++;
        }
    }
    while (index_1<=mid){
        merge[x]=arr[index_1];
        x++;
        index_1++;
    }
    while(index_2<=ei){
        merge[x]=arr[index_2];
        x++;
        index_2++;
    }
    
    for(int i=0 ,j=si;i<range;i++,j++){
        arr[j]=merge[i];
    }
}

void divide(int arr[],int si,int ei){      //si->starting index and ei->ending index
    if(si>=ei){
        return;
    }
    int mid = si + (ei-si)/2;
    divide(arr,si,mid);
    divide(arr,mid+1,ei);
    conqueer(arr,si,mid,ei);
}

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements: ");
     for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    divide(arr,0,n-1);
    printf("The sorted array is :");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
}



// output->
// Enter the size of array: 5
// Enter the elements: 45 23 12 67 1
// The sorted array is :1 12 23 45 67


// Enter the size of array: 4
// Enter the elements: -23 -1 -21 -65
// The sorted array is :-65 -23 -21 -1

