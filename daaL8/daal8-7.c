#include <stdio.h>

#define MAXN 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

void rodCuttingWithReconstruction(int price[], int n) {
    int dp[n + 1];
    int choice[n + 1];
    int i, j;

    dp[0] = 0;

    for (i = 1; i <= n; i++) {
        dp[i] = -1;
        choice[i] = -1;

        for (j = 1; j <= i; j++) {
            int value = price[j] + dp[i - j];
            if (dp[i] < value) {
                dp[i] = value;
                choice[i] = j;
            }
        }
    }

    printf("Maximum profit for rod length %d is: %d\n", n, dp[n]);

    printf("Piece sizes used: ");
    while (n > 0) {
        printf("%d ", choice[n]);
        n = n - choice[n];
    }
    printf("\n");
}

int main() {
    int price[11];
    int n = 8;

    price[1] = 1;
    price[2] = 5;
    price[3] = 8;
    price[4] = 9;
    price[5] = 10;
    price[6] = 17;
    price[7] = 17;
    price[8] = 20;
    price[9] = 24;
    price[10] = 30;

    rodCuttingWithReconstruction(price, n);

    return 0;
}