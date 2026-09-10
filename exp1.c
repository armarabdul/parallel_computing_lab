#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *temp = malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];

    free(temp);
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void parallelMergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSort(a, low, mid);

            #pragma omp section
            mergeSort(a, mid + 1, high);
        }

        merge(a, low, mid, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));

    // Generate same data for both arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100000;
        b[i] = a[i];
    }

    // Sequential Merge Sort
    double start = omp_get_wtime();

    mergeSort(a, 0, n - 1);

    double end = omp_get_wtime();

    printf("\nSequential Merge Sort Time: %f seconds\n", end - start);

    // Parallel Merge Sort
    start = omp_get_wtime();

    parallelMergeSort(b, 0, n - 1);

    end = omp_get_wtime();

    printf("Parallel Merge Sort Time:   %f seconds\n", end - start);

    free(a);
    free(b);

    return 0;
}

