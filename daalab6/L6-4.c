#include <stdio.h>

#define MAX 1000

int a[MAX];

void reverse(int l, int r)
{
    while (l < r)
    {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;

        l++;
        r--;
    }
}

/*
   Swap two adjacent blocks:

   A B  ->  B A

   using three reversals.
*/
void swapBlocks(int l1, int r1, int l2, int r2)
{
    reverse(l1, r1);
    reverse(l2, r2);
    reverse(l1, r2);
}

/*
   Partition [l, r] according to pivot.

   Values <= pivot are moved to the left.
   Values > pivot are moved to the right.

   This recursive procedure uses reversals.
*/
void partition(int l, int r, int pivot)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    partition(l, mid, pivot);
    partition(mid + 1, r, pivot);

    /*
       Find the first element > pivot
       in the left part.
    */

    int firstRight = l;

    while (firstRight <= mid &&
           a[firstRight] <= pivot)
    {
        firstRight++;
    }

    /*
       Find the first element <= pivot
       in the right part.
    */

    int firstLeft = mid + 1;

    while (firstLeft <= r &&
           a[firstLeft] > pivot)
    {
        firstLeft++;
    }

    if (firstRight <= mid &&
        firstLeft <= r)
    {
        /*
           Exchange the two middle blocks.
        */

        int leftEnd = mid;
        int rightStart = firstLeft;

        reverse(firstRight, leftEnd);
        reverse(rightStart, r);
        reverse(firstRight, r);
    }
}

void sortByReversal(int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    /*
       Partition according to value.
    */

    partition(l, r, mid);

    /*
       Now values <= mid should be
       on the left and larger values
       on the right.

       Recursively sort both halves.
    */

    sortByReversal(l, mid);
    sortByReversal(mid + 1, r);
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter permutation:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sortByReversal(0, n - 1);

    printf("Sorted permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}