#include <stdio.h>

typedef struct
{
    int min;
    int max;
} Result;

Result findMinMax(int a[], int low, int high)
{
    Result r, left, right;

    /* Only one element */
    if (low == high)
    {
        r.min = a[low];
        r.max = a[low];
        return r;
    }

    /* Two elements */
    if (high == low + 1)
    {
        if (a[low] < a[high])
        {
            r.min = a[low];
            r.max = a[high];
        }
        else
        {
            r.min = a[high];
            r.max = a[low];
        }

        return r;
    }

    int mid = (low + high) / 2;

    left = findMinMax(a, low, mid);
    right = findMinMax(a, mid + 1, high);

    if (left.min < right.min)
        r.min = left.min;
    else
        r.min = right.min;

    if (left.max > right.max)
        r.max = left.max;
    else
        r.max = right.max;

    return r;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Result r = findMinMax(a, 0, n - 1);

    printf("\nMinimum = %d\n", r.min);
    printf("Maximum = %d\n", r.max);

    return 0;
}