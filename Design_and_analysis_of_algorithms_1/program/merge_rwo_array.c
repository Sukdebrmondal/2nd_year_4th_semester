#include <stdio.h>

void merge(int a[], int b[], int m, int n, int c[]) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    
    while (i < m) {
        c[k++] = a[i++];
    }

    while (j < n) {
        c[k++] = b[j++];
    }


    printf("\nThe Merged Sorted Array is: ");
    for (int x = 0; x < m + n; x++) {
        printf("%d ", c[x]);
    }
    printf("\n");
}

int main() {
    int m, n;
    printf("Enter the size of the first array: ");
    scanf("%d", &m);
    int a[m]; 
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]); 
    }
    printf("Elements of the first array: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]); 
    }
    printf("\n");

    
    printf("Enter the size of the second array: ");
    scanf("%d", &n);
    int b[n]; 
    printf("Enter the elements of the second array: ");
    for (int j = 0; j < n; j++) {
        scanf("%d", &b[j]); 
    }

    printf("Elements of the second array: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", b[j]); 
    }
    printf("\n");

    int c[m + n]; 
    merge(a, b, m, n, c);

    return 0;
}