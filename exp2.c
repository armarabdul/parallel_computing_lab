#include <stdio.h>
#include <omp.h>

int main()
{
    int n;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    #pragma omp parallel
    {
        #pragma omp for schedule(static, 2)
        for (int i = 0; i < n; i++)
        {
            printf("Thread %d : Iteration %d\n",
                   omp_get_thread_num(), i);
        }
    }

    return 0;
}
