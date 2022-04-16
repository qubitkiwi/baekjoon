#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) 
        return -1; 
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(void)
{
    int N, i, j, sum=0, anw=0;
    scanf("%d", &N);
    int arr[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int),  compare);


    sum = arr[0];
    anw = sum;
    for(i=1; i<N; i++)
    {
        sum = sum + arr[i];
        anw = anw + sum;
    }

    printf("%d\n", anw);


    return 0;
}