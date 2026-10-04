#include <stdio.h>

#define MAX 100

double min(double a, double b) {
    return (a < b) ? a : b;
}

void optimalBST(double p[], int n) {
    double dp[MAX][MAX];
    double root[MAX][MAX];
    int i, j, k, l;

    for (i = 0; i < n; i++) {
        dp[i][i] = p[i];
        root[i][i] = i;
    }

    for (l = 2; l <= n; l++) {
        for (i = 0; i <= n - l; i++) {
            j = i + l - 1;
            dp[i][j] = 1e9;
            root[i][j] = i;

            for (k = i; k <= j; k++) {
                double left = (k == i) ? 0 : dp[i][k - 1];
                double right = (k == j) ? 0 : dp[k + 1][j];
                double total = left + right + p[k];

                if (total < dp[i][j]) {
                    dp[i][j] = total;
                    root[i][j] = k;
                }
            }
        }
    }

    printf("Optimal BST cost = %.2f\n", dp[0][n - 1]);
}

int main() {
    double p[] = {0.15, 0.10, 0.05, 0.10, 0.20};
    int n = sizeof(p) / sizeof(p[0]);

    optimalBST(p, n);

    return 0;
}