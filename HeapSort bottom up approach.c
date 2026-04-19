#include <stdio.h>

void heapBottomUp(int H[], int n)
{
    int i, k, v, j, heap;

    for(i = n/2; i >= 1; i--)
    {
        k = i;
        v = H[k];
        heap = 0;

        while(!heap && 2*k <= n)
        {
            j = 2*k;

            if(j < n)              // two children
            {
                if(H[j] < H[j+1])
                    j = j + 1;
            }

            if(v >= H[j])
                heap = 1;
            else
            {
                H[k] = H[j];
                k = j;
            }
        }

        H[k] = v;
    }
}

int main()
{
    int H[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &H[i]);

    heapBottomUp(H, n);

    printf("Heap elements:\n");
    for(i = 1; i <= n; i++)
        printf("%d ", H[i]);

    return 0;
}
