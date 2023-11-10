#include <stdio.h>

int trap(int height[], int n) {
    if (n <= 2) {
        return 0; // Cannot trap water with less than 3 bars
    }

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int trapped_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > left_max) {
                left_max = height[left];
            } else {
                trapped_water += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] > right_max) {
                right_max = height[right];
            } else {
                trapped_water += right_max - height[right];
            }
            right--;
        }
    }

    return trapped_water;
}

int main() {
    int n;

    printf("Enter the number of bars in the elevation map: ");
    scanf("%d", &n);

    int height[n];

    printf("Enter the heights of the bars:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int trapped_water = trap(height, n);
    printf("The amount of trapped water is: %d\n", trapped_water);

    return 0;
}
//Output-
Enter the number of bars in the elevation map: 10
Enter the heights of the bars:
20
30
40
50
60
70
80
90
100
110
The amount of trapped water is: 180