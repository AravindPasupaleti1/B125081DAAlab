#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    FILE *fp;
    int n, i;
    int a[1000];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000)
    {
        printf("Invalid number of elements\n");
        return 0;
    }

    /* Generate random elements and store in file */
    fp = fopen("lab5_03.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        int num = rand() % 1000;
        fprintf(fp, "%d ", num);
    }

    fclose(fp);

    /* Read elements from file */
    fp = fopen("lab5_03.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    printf("\nElements before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    /* Quick Sort */
    quickSort(a, 0, n - 1);

    printf("\n\nElements after Quick Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}