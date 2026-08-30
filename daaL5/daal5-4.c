#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements from heap */
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);

        heapify(a, i, 0);
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
    fp = fopen("lab5_04.txt", "w");

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
    fp = fopen("lab5_04.txt", "r");

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

    /* Heap Sort */
    heapSort(a, n);

    printf("\n\nElements after Heap Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}