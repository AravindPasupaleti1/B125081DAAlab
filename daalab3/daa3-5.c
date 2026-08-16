#include <stdio.h>

void add(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiplySpecial(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A1[k][k], A2[k][k];
    int B1[k][k], B2[k][k];

    int X[k][k], Y[k][k];
    int P[k][k], Q[k][k];

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    /* P = (A1 + A2)(B1 + B2) */
    add(k, A1, A2, X);
    add(k, B1, B2, Y);
    multiplySpecial(k, X, Y, P);

    /* Q = (A1 - A2)(B1 - B2) */
    subtract(k, A1, A2, X);
    subtract(k, B1, B2, Y);
    multiplySpecial(k, X, Y, Q);

    /*
       C1 = (P + Q) / 2
       C2 = (P - Q) / 2
    */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int C1 = (P[i][j] + Q[i][j]) / 2;
            int C2 = (P[i][j] - Q[i][j]) / 2;

            C[i][j] = C1;
            C[i][j + k] = C2;
            C[i + k][j] = C2;
            C[i + k][j + k] = C1;
        }
    }
}

int main()
{
    int n;

    printf("Enter n (power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    multiplySpecial(n, A, B, C);

    printf("\nProduct Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}