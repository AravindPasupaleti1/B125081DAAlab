#include <stdio.h>

unsigned long long minMoves(int n)
{
    unsigned long long a = 1;
    unsigned long long b = 2;
    unsigned long long c;

    if (n == 1)
        return a;

    if (n == 2)
        return b;

    for (int i = 3; i <= n; i++)
    {
        c = b + 2 * a + 1;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    printf("Minimum moves = %llu\n", minMoves(n));

    return 0;
}