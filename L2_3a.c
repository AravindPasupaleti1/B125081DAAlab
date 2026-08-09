#include <stdio.h>
void merge(int a[], int b[], int result[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    // Compare elements of both arrays
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }
    // Copy remaining elements of first array
    while (i < n1)
        result[k++] = a[i++];
    // Copy remaining elements of second array
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
    // Temporary array
    int result[k * n];
    // Initially copy first array
    for (int i = 0; i < n; i++)
        result[i] = a[0][i];
    int currentSize = n;
    // Merge one array at a time
    for (int i = 1; i < k; i++)
    {
        int temp[k * n];
        merge(result, a[i], temp, currentSize, n);
        currentSize = currentSize + n;
        // Copy temp back to result
        for (int j = 0; j < currentSize; j++)
            result[j] = temp[j];
    }
    printf("\nFinal sorted array:\n");
    for (int i = 0; i < k * n; i++)
        printf("%d ", result[i]);
    return 0;
}