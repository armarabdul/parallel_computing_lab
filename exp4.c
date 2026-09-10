#include <stdio.h>
#include <omp.h>

int isPrime(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    // Serial
    double start = omp_get_wtime();

    printf("\nPrime numbers (Serial):\n");

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }

    double end = omp_get_wtime();

    printf("\nSerial Time: %f seconds\n", end - start);


    // Parallel
    start = omp_get_wtime();

    printf("\nPrime numbers (Parallel):\n");

    #pragma omp parallel for
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }

    end = omp_get_wtime();

    printf("\nParallel Time: %f seconds\n", end - start);

    return 0;
}
