#include <stdio.h>
#include <math.h>

void findMaxSecond(int a[], int n)
{
    int largest = a[0];
    int second = -2147483648;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if (a[i] > second && a[i] != largest)
        {
            second = a[i];
        }
    }

    printf("Maximum = %d\n", largest);
    printf("Second largest = %d\n", second);
}

void meanStdDev(int a[], int n)
{
    double sum = 0, mean, variance = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    mean = sum / n;

    for (int i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance /= n;

    printf("Mean = %.2f\n", mean);
    printf("Standard Deviation = %.2f\n", sqrt(variance));
}

void median(int a[], int n)
{
    int b[100];

    for (int i = 0; i < n; i++)
        b[i] = a[i];

    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    double med;

    if (n % 2 == 1)
        med = b[n / 2];
    else
        med = (b[n / 2 - 1] + b[n / 2]) / 2.0;

    printf("Median = %.2f\n", med);
}

void mode(int a[], int n)
{
    int maxCount = 0;
    int modeValue = a[0];

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            modeValue = a[i];
        }
    }

    printf("Mode = %d\n", modeValue);
}

void removeDuplicates(int a[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
                j--;
            }
        }
    }
}

void reverseArray(int a[], int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
}

void partitionArray(int a[], int n, int pivot)
{
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if (a[j] < pivot)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[100], n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    findMaxSecond(a, n);
    meanStdDev(a, n);
    median(a, n);
    mode(a, n);

    removeDuplicates(a, &n);

    printf("After removing duplicates: ");
    display(a, n);

    reverseArray(a, n);

    printf("After reversing: ");
    display(a, n);

    int pivot;
    printf("Enter pivot: ");
    scanf("%d", &pivot);

    partitionArray(a, n, pivot);

    printf("After partitioning: ");
    display(a, n);

    return 0;
}