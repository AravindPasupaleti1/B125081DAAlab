#include <stdio.h>

#define MAXN 100
#define MAXW 1000

int main() {
    int n, W;
    int weight[MAXN], profit[MAXN];
    int dp[MAXN + 1][MAXW + 1];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    // Initialize dp table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = dp[i - 1][w];

                int take = profit[i - 1] + dp[i - 1][w - weight[i - 1]];
                if (take > dp[i][w]) {
                    dp[i][w] = take;
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum profit = %d\n", dp[n][W]);
    return 0;
}