#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of element : ");
    scanf("%d", &n);
    int arr[n];
    // taking input
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Your array is : ");
    // display all values
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nPositive number in your array : ");
    // display all values
    for (int i = 0; i < n; i++)
    {
            printf("%d\t", arr[i]*arr[i]);
    }

    return 0;
}

Output-
Enter the number of element : 12
Enter the 1 element : 5
Enter the 2 element : 2
Enter the 3 element : 6
Enter the 4 element : 4
Enter the 5 element : 1
Enter the 6 element : 3
Enter the 7 element : 7
Enter the 8 element : 8
Enter the 9 element : 9
Enter the 10 element : 15
Enter the 11 element : 21
Enter the 12 element : 13
Your array is : 5	2	6	4	1	3	7	8	9	15	21	13	
Positive number in your array : 25	4	36	16	1	9	49	64	81	225	441	169	