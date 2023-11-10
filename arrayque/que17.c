#include <stdio.h>

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int mergedArr[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    printf("Enter the size of the first sorted array: ");
    scanf("%d", &size1);

    int arr1[size1];

    printf("Enter the elements of the first sorted array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second sorted array: ");
    scanf("%d", &size2);

    int arr2[size2];

    printf("Enter the elements of the second sorted array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int mergedSize = size1 + size2;
    int mergedArr[mergedSize];

    mergeSortedArrays(arr1, size1, arr2, size2, mergedArr);

    printf("Merged sorted array:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArr[i]);
    }

    return 0;
} 
//Output-
Enter the size of the first sorted array: 2
Enter the elements of the first sorted array:
12
15
Enter the size of the second sorted array: 3
Enter the elements of the second sorted array:
10
12
9
Merged sorted array:
10 12 9 12 15

