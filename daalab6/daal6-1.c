#include <stdio.h>

long long fib_dp(int n) {
    if (n <= 1) return n;

    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("The %dth Fibonacci number is: %lld\n", n, fib_dp(n));

    return 0;
}
