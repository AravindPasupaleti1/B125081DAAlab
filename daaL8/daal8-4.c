#include <stdio.h>

int lisLength(int arr[], int n) {
    int dp[n];
    int i, j, maxLen = 0;

    for (i = 0; i < n; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of Longest Increasing Subsequence is: %d\n", lisLength(arr, n));

    return 0;
}