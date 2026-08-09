#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* NORMAL MERGE SORT  */
void merge(int a[], int left, int mid, int right, long long *count)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int size = right - left + 1;
    int *temp = (int *)malloc(size * sizeof(int));
    while (i <= mid && j <= right)
    {
        (*count)++;
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];
    for (i = left, k = 0; i <= right; i++, k++)
        a[i] = temp[k];
    free(temp);
}
void mergeSort(int a[], int left, int right, long long *count)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid, count);
        mergeSort(a, mid + 1, right, count);
        merge(a, left, mid, right, count);
    }
}
/* THREE-WAY MERGE SORT */

void merge3(int a[], int left, int mid1, int mid2,
            int right, long long *count)
{
    int i = left;
    int j = mid1 + 1;
    int k = mid2 + 1;
    int p = 0;
    int size = right - left + 1;
    int *temp = (int *)malloc(size * sizeof(int));
    while (i <= mid1 || j <= mid2 || k <= right)
    {
        /* All three parts have elements */
        if (i <= mid1 && j <= mid2 && k <= right)
        {
            (*count)++;
            if (a[i] <= a[j] && a[i] <= a[k])
                temp[p++] = a[i++];
            else if (a[j] <= a[i] && a[j] <= a[k])
                temp[p++] = a[j++];
            else
                temp[p++] = a[k++];
        }
        /* First and second parts */
        else if (i <= mid1 && j <= mid2)
        {
            (*count)++;

            if (a[i] <= a[j])
                temp[p++] = a[i++];
            else
                temp[p++] = a[j++];
        }
        /* First and third parts */
        else if (i <= mid1 && k <= right)
        {
            (*count)++;

            if (a[i] <= a[k])
                temp[p++] = a[i++];
            else
                temp[p++] = a[k++];
        }
        /* Second and third parts */
        else if (j <= mid2 && k <= right)
        {
            (*count)++;

            if (a[j] <= a[k])
                temp[p++] = a[j++];
            else
                temp[p++] = a[k++];
        }
        /* Remaining elements */
        else if (i <= mid1)
            temp[p++] = a[i++];

        else if (j <= mid2)
            temp[p++] = a[j++];

        else
            temp[p++] = a[k++];
    }
    for (i = left, p = 0; i <= right; i++, p++)
        a[i] = temp[p];

    free(temp);
}
void mergeSort3(int a[], int left, int right, long long *count)
{
    if (left < right)
    {
        int n = right - left + 1;

        int mid1 = left + (n - 1) / 3;
        int mid2 = left + 2 * (n - 1) / 3;

        /* Sort first third */
        mergeSort3(a, left, mid1, count);

        /* Sort second third */
        if (mid1 + 1 <= mid2)
            mergeSort3(a, mid1 + 1, mid2, count);

        /* Sort third third */
        if (mid2 + 1 <= right)
            mergeSort3(a, mid2 + 1, right, count);

        /* Merge three sorted parts */
        merge3(a, left, mid1, mid2, right, count);
    }
}
int main()
{
    FILE *data;
    FILE *gnuplot;
    srand(time(NULL));
    data = fopen("comparison.dat", "w");
    if (data == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    printf("N\tMerge Sort\t3-Way Merge Sort\n");
    for (int n = 100; n <= 5000; n += 100)
    {
        int *a = (int *)malloc(n * sizeof(int));
        int *b = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100000;
            b[i] = a[i];
        }
        long long count1 = 0;
        long long count2 = 0;
        /* Normal merge sort */
         mergeSort(a, 0, n - 1, &count1);

        /* Three-way merge sort */
        mergeSort3(b, 0, n - 1, &count2);

        printf("%d\t%lld\t\t%lld\n",
               n, count1, count2);

        /* Save data for GNU Plot */
        fprintf(data, "%d %lld %lld\n",
                n, count1, count2);

        free(a);
        free(b);
    }

    fclose(data);
    gnuplot = fopen("plot.gnu", "w");

    fprintf(gnuplot,
            "set title 'Merge Sort vs 3-Way Merge Sort'\n"
            "set xlabel 'Input Size (n)'\n"
            "set ylabel 'Number of Comparisons'\n"
            "set grid\n"
            "set key left top\n"
            "plot 'comparison.dat' using 1:2 with linespoints "
            "title 'Normal Merge Sort', "
            "'comparison.dat' using 1:3 with linespoints "
            "title '3-Way Merge Sort'\n");

    fclose(gnuplot);
    printf("\nGenerating graph...\n");
    system("gnuplot -persist plot.gnu");
    printf("\nGraph generated successfully!\n");
    return 0;
}