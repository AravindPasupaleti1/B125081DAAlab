#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI acos(-1.0)

void fft(double complex a[], int n, int invert)
{
    // Bit reversal
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;

        for (; j & bit; bit >>= 1)
            j ^= bit;

        j ^= bit;

        if (i < j)
        {
            double complex temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    // FFT
    for (int len = 2; len <= n; len <<= 1)
    {
        double angle = 2 * PI / len;

        if (invert)
            angle = -angle;

        double complex wlen = cos(angle) + I * sin(angle);

        for (int i = 0; i < n; i += len)
        {
            double complex w = 1;

            for (int j = 0; j < len / 2; j++)
            {
                double complex u = a[i + j];
                double complex v = a[i + j + len / 2] * w;

                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;

                w *= wlen;
            }
        }
    }

    if (invert)
    {
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
}

int main()
{
    int m, n;

    printf("Enter length of A: ");
    scanf("%d", &m);

    printf("Enter length of B: ");
    scanf("%d", &n);

    int size = 1;

    while (size < m + n - 1)
        size <<= 1;

    double complex *A =
        calloc(size, sizeof(double complex));

    double complex *B =
        calloc(size, sizeof(double complex));

    printf("Enter elements of A:\n");

    for (int i = 0; i < m; i++)
    {
        double x;
        scanf("%lf", &x);
        A[i] = x;
    }

    printf("Enter elements of B:\n");

    for (int i = 0; i < n; i++)
    {
        double x;
        scanf("%lf", &x);
        B[i] = x;
    }

    fft(A, size, 0);
    fft(B, size, 0);

    // Point-wise multiplication
    for (int i = 0; i < size; i++)
        A[i] *= B[i];

    fft(A, size, 1);

    printf("Convolution:\n");

    for (int i = 0; i < m + n - 1; i++)
        printf("%.0f ", creal(A[i]));

    printf("\n");

    free(A);
    free(B);

    return 0;
}