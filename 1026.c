#include <stdio.h>
#include <stdlib.h>

int compare1(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) 
        return -1; 
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int compare2(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 > num2) 
        return -1; 
    
    if (num1 < num2)
        return 1;
    
    return 0;
}

int main(void)
{
    int N, i, j, sum=0;
    scanf("%d", &N);
    int A[N];
    int B[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }
    for(i=0; i<N; i++)
    {
        scanf("%d", &B[i]);
    }


    qsort(A, N, sizeof(int),  compare1);
    qsort(B, N, sizeof(int),  compare2);

    for(i=0; i<N; i++)
    {
        sum += A[i]*B[i];
    }

    printf("%d\n", sum);


    return 0;
}