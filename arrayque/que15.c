#include <stdio.h>

int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return (originalNum == reversedNum);
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Palindrome numbers in the array are:\n");
    for (int i = 0; i < n; i++) {
        if (isPalindrome(arr[i])) {
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}
//Output -
Enter the number of elements in the array: 10
Enter the array elements:
11
12
13
14
15
161
145
141
152
212
Palindrome numbers in the array are:
11
161
141
212