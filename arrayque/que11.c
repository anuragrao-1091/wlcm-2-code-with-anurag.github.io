#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    
    // Taking inputs
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element :", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("The similar elements in array :%d\n", arr[j]);
            }
        }
    }

    return 0;
}
//Output-
Enter the number of elements : 5
Enter 1 element :10
Enter 2 element :12
Enter 3 element :10
Enter 4 element :13
Enter 5 element :15
The similar elements in array :10