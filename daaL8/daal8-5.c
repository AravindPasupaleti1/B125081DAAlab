#include <stdio.h>

int maxSumIncreasingSubsequence(int arr[], int n) {
    int dp[n];
    int i, j;
    int maxSum = 0;

    for (i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + arr[i] > dp[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
        if (dp[i] > maxSum) {
            maxSum = dp[i];
        }
    }

    return maxSum;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum sum of increasing subsequence is: %d\n", maxSumIncreasingSubsequence(arr, n));

    return 0;
}