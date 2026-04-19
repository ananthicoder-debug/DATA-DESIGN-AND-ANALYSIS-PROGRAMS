#include <stdio.h>

int main()
{
    int A[100], n, i, j, v;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for(i = 1; i <= n-1; i++)
    {
        v = A[i];          // key value
        j = i - 1;

        while(j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j = j - 1;
        }

        A[j+1] = v;
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
