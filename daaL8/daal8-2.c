#include<stdio.h>
#include<stdlib.h>
long long countWays(int coins[], int n, int amount) {
    long long* dp = (long long*)malloc((amount + 1) * sizeof(long long));
    dp[0] = 1; 
    
    for (int i = 1; i <= amount; i++) {
        dp[i] = 0; 
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]]; 
        }
    }
    
    long long result = dp[amount];
    free(dp); // Free the allocated memory
    return result;
}

int main() {
    int n, v;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);
    int coins[n];
    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("Enter the target amount: ");
    scanf("%d", &v);
    
    long long result = countWays(coins, n, v);
    printf("Number of ways to make the target amount: %lld\n", result);
    
    return 0;
}