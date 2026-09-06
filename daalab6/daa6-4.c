#include <stdio.h>
#include <limits.h>

int main()
{
    int N, i, j, k, L;

    printf("Enter N: ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter array elements:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int dp[N][N];

    // Cost is zero when multiplying one matrix
    for (i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    // L is chain length
    for (L = 2; L < N; L++)
    {
        for (i = 1; i < N - L + 1; i++)
        {
            j = i + L - 1;

            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d\n",
           dp[1][N - 1]);

    return 0;
}