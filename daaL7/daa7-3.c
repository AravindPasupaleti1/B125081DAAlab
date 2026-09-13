#include <stdio.h>
#include <limits.h>

#define MAX 30

unsigned long long dp[MAX + 1];

unsigned long long power2(int n)
{
    unsigned long long result = 1;

    for (int i = 0; i < n; i++)
        result *= 2;

    return result;
}

void solve(int n)
{
    if (n == 0)
        return;

    if (n == 1)
    {
        printf("Move disk 1\n");
        return;
    }

    int bestK = 1;
    unsigned long long best = ULLONG_MAX;

    for (int k = 1; k < n; k++)
    {
        unsigned long long moves =
            2 * dp[k] + power2(n - k) - 1;

        if (moves < best)
        {
            best = moves;
            bestK = k;
        }
    }

    printf("For n = %d, choose k = %d\n", n, bestK);
    printf("Minimum moves = %llu\n", best);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = ULLONG_MAX;

        for (int k = 1; k < i; k++)
        {
            unsigned long long moves =
                2 * dp[k] + power2(i - k) - 1;

            if (moves < dp[i])
                dp[i] = moves;
        }
    }

    printf("Minimum moves = %llu\n", dp[n]);

    solve(n);

    return 0;
}