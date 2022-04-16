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
    int N, i, j, max, min, t;
    int *rope;
    scanf("%d", &N);

    rope = malloc(N*sizeof(int));
    for(i=0; i<N; i++)
    {
        scanf("%d", &rope[i]);
    }

    qsort(rope, N, sizeof(int), compare);
    max = rope[N-1];
    
    for(i=0; i<N; i++)
    {
        min = rope[i];
        t = min*(N-i);
        if(max < t)
        {
            max = t;
        }
    }

    printf("%d\n", max);

    return 0;
}