#include <stdio.h>
void merge(int a[], int b[], int result[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    // Merge while both arrays have elements
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }
    // Copy remaining elements
    while (i < n1)
        result[k++] = a[i++];

    while (j < n2)
        result[k++] = b[j++];
}
int main()
{
    int k, n;
    printf("Enter number of arrays: ");
    scanf("%d", &k);
    printf("Enter number of elements in each array: ");
    scanf("%d", &n);
    int a[k][n];
    printf("Enter the sorted arrays:\n");
    for (int i = 0; i < k; i++)
    {
        printf("Array %d: ", i + 1);
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    // Store all arrays in one 2D structure
    int current[k * n];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            current[i * n + j] = a[i][j];
        }
    }
    int arrays = k;
    int size = n;
    // Keep merging pairs
    while (arrays > 1)
    {
        int next[k * n];
        int newArrays = 0;
        for (int i = 0; i < arrays; i += 2)
        {
            merge(
                &current[i * size],
                &current[(i + 1) * size],
                &next[newArrays * size * 2],
                size,
                size
            );
            newArrays++;
        }
        // New array size becomes double
        size = size * 2;
        arrays = newArrays;
        // Copy next level back
        for (int i = 0; i < k * n; i++)
            current[i] = next[i];
    }
    printf("\nFinal sorted array:\n");
    for (int i = 0; i < k * n; i++)
        printf("%d ", current[i]);
    return 0;
}