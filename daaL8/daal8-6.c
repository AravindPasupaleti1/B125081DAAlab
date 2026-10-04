#include <stdio.h>
#include <string.h>

#define MAX 100

enum Operation {
    MATCH,
    INSERT,
    DELETE,
    REPLACE
};

typedef struct {
    int cost;
    enum Operation op;
} Cell;

int min3(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

void printTraceback(Cell dp[][MAX], char *s1, char *s2, int i, int j) {
    if (i == 0 && j == 0) {
        return;
    }

    if (dp[i][j].op == MATCH) {
        printTraceback(dp, s1, s2, i - 1, j - 1);
        printf("Match/No change: %c\n", s1[i - 1]);
    } else if (dp[i][j].op == INSERT) {
        printTraceback(dp, s1, s2, i, j - 1);
        printf("Insert: %c\n", s2[j - 1]);
    } else if (dp[i][j].op == DELETE) {
        printTraceback(dp, s1, s2, i - 1, j);
        printf("Delete: %c\n", s1[i - 1]);
    } else if (dp[i][j].op == REPLACE) {
        printTraceback(dp, s1, s2, i - 1, j - 1);
        printf("Replace: %c -> %c\n", s1[i - 1], s2[j - 1]);
    }
}

int editDistanceWithTraceback(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    Cell dp[MAX][MAX];

    dp[0][0].cost = 0;
    dp[0][0].op = MATCH;

    for (int i = 1; i <= m; i++) {
        dp[i][0].cost = i;
        dp[i][0].op = DELETE;
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j].cost = j;
        dp[0][j].op = INSERT;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j].cost = dp[i - 1][j - 1].cost;
                dp[i][j].op = MATCH;
            } else {
                int replaceCost = dp[i - 1][j - 1].cost + 1;
                int insertCost = dp[i][j - 1].cost + 1;
                int deleteCost = dp[i - 1][j].cost + 1;

                int min = min3(replaceCost, insertCost, deleteCost);

                if (min == replaceCost) {
                    dp[i][j].cost = replaceCost;
                    dp[i][j].op = REPLACE;
                } else if (min == insertCost) {
                    dp[i][j].cost = insertCost;
                    dp[i][j].op = INSERT;
                } else {
                    dp[i][j].cost = deleteCost;
                    dp[i][j].op = DELETE;
                }
            }
        }
    }

    printf("Minimum edit distance: %d\n", dp[m][n].cost);
    printf("Traceback operations:\n");
    printTraceback(dp, s1, s2, m, n);

    return dp[m][n].cost;
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";

    editDistanceWithTraceback(s1, s2);

    return 0;
}