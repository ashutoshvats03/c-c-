#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void merge(int *a, int l, int mid, int h){
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int *left = malloc(sizeof(int) * n1);
    int *right = malloc(sizeof(int) * n2);

    // Copy data to temporary arrays left[] and right[]
    for (i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];

    // Merge the temporary arrays back into a[]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void mergesort(int *a, int l, int h){
    if (l < h) {
        int mid = (l + h) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main(){
    int i, n1;
    printf("Enter the number of elements you want to enter in the array: ");
    scanf("%d", &n1);
    int *a = malloc(sizeof(int) * n1);
    
    printf("Enter %d elements:\n", n1);
    for (i = 0; i < n1; i++){
        scanf("%d", &a[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < n1; i++){
        printf("%d\t", a[i]);
    }

    mergesort(a, 0, n1 - 1); 

    printf("\nSorted array:\n");
    for (i = 0; i < n1; i++){
        printf("%d\t", a[i]);
    }

    free(a); // Don't forget to free the allocated memory

    return 0;
}
