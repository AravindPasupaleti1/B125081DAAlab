#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

int quickSelect(int a[], int low, int high, int k)
{
    if (low == high)
        return a[low];

    int pivotIndex = partition(a, low, high);

    if (pivotIndex == k)
        return a[pivotIndex];

    else if (k < pivotIndex)
        return quickSelect(a, low, pivotIndex - 1, k);

    else
        return quickSelect(a, pivotIndex + 1, high, k);
}

int main()
{
    int n, k, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k < 1 || k > n)
    {
        printf("Invalid value of K\n");
        return 0;
    }

    result = quickSelect(a, 0, n - 1, k - 1);

    printf("%dth smallest element = %d\n", k, result);

    return 0;
}