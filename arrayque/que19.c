#include <stdio.h>
#include <stdbool.h>

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

    //check local minima
    for (int i = 1; i < n-1; i++)
    {
        if (arr[i-1]<arr[i]&&arr[i]>arr[i+1])
        {
            printf("%d is local maxima \n",arr[i]);
        }     
    }
    return 0;
}

// OUTPUT :
/*
Enter the number of element : 6
Enter the 1 element : 12
Enter the 2 element : 34
Enter the 3 element : 5
Enter the 4 element : 67
Enter the 5 element : 8
Enter the 6 element : 8
34 is local maxima
67 is local maxima
*/