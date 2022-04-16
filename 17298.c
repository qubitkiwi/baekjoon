#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j, sp=0;
    int *arr, *NGE, *stack;

    scanf("%d", &N);
    arr = (int *)malloc(N*sizeof(int));
    NGE = (int *)malloc(N*sizeof(int));
    stack = (int *)malloc(N*sizeof(int));

    for(i=0; i<N; i++)
        scanf("%d", &arr[i]);
    
    NGE[N-1] = -1;
    stack[sp++] = arr[N-1];

    for(i=N-2; i>=0; i--)
    {
        while(sp-->=0)
        {
            if(stack[sp] > arr[i])
            {
                NGE[i] = stack[sp];
                stack[++sp] = arr[i];
                sp++;
                break;
            }

            if(sp == 0)
            {
                NGE[i] = -1;
                stack[sp++] = arr[i];
                break;
            }
        }
    }

    for(i=0; i<N; i++)
        printf("%d ", NGE[i]);
    printf("\n");

    free(arr);
    free(NGE);
    free(stack);
    return 0;
}



/*

1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10 -1

1  2 1  2 1  2 1  2
2 -1 2 -1 2 -1 2 -1

 3 2 1  3 2 1  3  2  1
-1 3 3 -1 3 3 -1 -1 -1

4  1  4   6  10   4  2   3
6  4  6  10  -1  -1  3  -1

              1
              4   4
   2          6   6
3  3  4  10  10  10 


 4  1  4   6  10   4  2   3
 6  4  6  10  -1  -1  3  -1

           1
    4      4
    6  6   6          2
   10 10  10  10   4  3   3 


10 9 8 7 6 5 4 3 2 1 11

s = 11 1
s = 11 2
s = 11 3
s = 11 4
s = 11 5
s = 11 6
s = 11 7



*/