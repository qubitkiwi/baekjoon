#include <stdio.h>
#include <stdlib.h>

int move_f(int A, int B, int N, int *jamp)
{
    int i, min;
    min = abs(A-B);

    for(i=0; i<N; i++)
    {
        if(min > abs(B-jamp[i])+1)
        {
            min = abs(B-jamp[i])+1;
        }
    }
    return min;    
}

int main()
{
    int A, B, N, i, *jamp, anw;
    scanf("%d %d", &A, &B);
    scanf("%d", &N);
    
    jamp = (int *)calloc(N, sizeof(int));
    
    for (i = 0; i < N; i++)
        scanf("%d", &jamp[i]);

    anw = move_f(A, B, N, jamp);
    printf("%d\n", anw);
    
    free(jamp);
    return 0;
}