#include <stdio.h>

int findDefective(int a[], int left, int right)
{
    if (left > right)
        return -1;

    if (left == right)
    {
        if (a[left] < 10)
            return left;
        else
            return -1;
    }

    int n = right - left + 1;

    int third = n / 3;

    int l1 = left;
    int r1 = left + third - 1;

    int l2 = r1 + 1;
    int r2 = l2 + third - 1;

    int l3 = r2 + 1;
    int r3 = right;

    int sum1 = 0, sum2 = 0;

    for (int i = l1; i <= r1; i++)
        sum1 += a[i];

    for (int i = l2; i <= r2; i++)
        sum2 += a[i];

    if (sum1 < sum2)
        return findDefective(a, l1, r1);

    else if (sum2 < sum1)
        return findDefective(a, l2, r2);

    else
        return findDefective(a, l3, r3);
}

int main()
{
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter weights of coins:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int index = findDefective(a, 0, n - 1);

    if (index == -1)
        printf("No defective coin found.\n");
    else
        printf("Possible defective coin is coin %d.\n", index + 1);

    return 0;
}