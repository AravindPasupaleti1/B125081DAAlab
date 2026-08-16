#include <stdio.h>

int binarySearch(int a[], int n, int x, int *comparisons)
{
    int low = 0, high = n - 1;
    *comparisons = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        (*comparisons)++;

        if (a[mid] == x)
            return mid;

        (*comparisons)++;

        if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int ternarySearch(int a[], int n, int x, int *comparisons)
{
    int low = 0, high = n - 1;
    *comparisons = 0;

    while (low <= high)
    {
        int third = (high - low) / 3;

        int mid1 = low + third;
        int mid2 = high - third;

        (*comparisons)++;

        if (a[mid1] == x)
            return mid1;

        (*comparisons)++;

        if (a[mid2] == x)
            return mid2;

        (*comparisons)++;

        if (x < a[mid1])
            high = mid1 - 1;
        else if (x > a[mid2])
            low = mid2 + 1;
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    int n, x;
    int binaryComp, ternaryComp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int b = binarySearch(a, n, x, &binaryComp);
    int t = ternarySearch(a, n, x, &ternaryComp);

    printf("\nBinary Search:\n");
    if (b != -1)
        printf("Element found at index %d\n", b);
    else
        printf("Element not found\n");

    printf("Comparisons = %d\n", binaryComp);

    printf("\nTernary Search:\n");
    if (t != -1)
        printf("Element found at index %d\n", t);
    else
        printf("Element not found\n");

    printf("Comparisons = %d\n", ternaryComp);

    if (binaryComp < ternaryComp)
        printf("\nBinary Search is better for this case.\n");
    else
        printf("\nTernary Search used fewer comparisons for this case.\n");

    return 0;
}