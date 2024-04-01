#include <stdio.h>

void merge_arrays(int arr1[], int arr2[], int size1, int size2) {
    int merge_size = size1 + size2;
    int merge[merge_size];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merge[k++] = arr1[i++];
        } else {
            merge[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merge[k++] = arr1[i++];
    }

    while (j < size2) {
        merge[k++] = arr2[j++];
    }

    for (int l = 0; l < merge_size; l++) {
        printf("%d ", merge[l]);
    }
}

int main() {
    int size1, size2;

    scanf("%d", &size1);
    int arr1[size1];
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &size2);
    int arr2[size2];
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    merge_arrays(arr1, arr2, size1, size2);

    return 0;
}
