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
    int T, test_case, i, j, N, M, cnt;
    int *A, *B, *find;

    
    scanf("%d", &T);
    for(test_case=0; test_case<T; test_case++)
    {
        cnt = 0;
        scanf("%d %d", &N, &M);
        A = malloc(N*sizeof(int));
        B = malloc(M*sizeof(int));

        for(i=0; i<N; i++)
        {
            scanf("%d", &A[i]);
        }
        for(i=0; i<M; i++)
        {
            scanf("%d", &B[i]);
        }
        
        qsort(A, N, sizeof(int), compare);
        qsort(B, M, sizeof(int), compare);


        for(i=0; i<N; i++)
        {
            for(j=M-1; j>=0; j--)
            {
                if(A[i] > B[j])
                {
                    cnt += j+1;
                    break;
                }
            }   
        }

        printf("%d\n", cnt);

    }

    return 0;
}