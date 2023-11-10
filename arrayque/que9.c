#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        if (k == pivotIndex)
            return arr[pivotIndex];
        else if (k < pivotIndex)
            return quickselect(arr, low, pivotIndex - 1, k);
        else
            return quickselect(arr, pivotIndex + 1, high, k);
    }
    return arr[low];
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k (1-based index): ");
    scanf("%d", &k);

    if (k >= 1 && k <= n) {
        int kthSmallest = quickselect(arr, 0, n - 1, k - 1);
        printf("The %d-th smallest value in the array is: %d\n", k, kthSmallest);
    } else {
        printf("Invalid value of k. Must be between 1 and %d.\n", n);
    }

    return 0;
}

//Output-
Enter the number of elements in the array: 10
Enter the array elements:
5
2
4
6
1
3
9
7
8
12
Enter the value of k (1-based index): 6
The 6-th smallest value in the array is: 6