#include <stdio.h>

int possibleMove(int pos, int n, int next)
{
    return (next == pos - 1 || next == pos + 1) &&
           next >= 1 && next <= n;
}

int main()
{
    int n;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    printf("\nShooting sequence:\n");

    for (int i = 2; i <= n - 1; i++)
        printf("%d ", i);

    for (int i = n - 2; i >= 2; i--)
        printf("%d ", i);

    printf("\n");

    printf("\nThe consecutive sweep strategy guarantees a hit.\n");

    return 0;
}