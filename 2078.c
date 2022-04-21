#include <stdio.h>

int* tree(int A, int B)
{
    static int RL[2] = {0, };

    while(1)
    {
        if(A==1)
        {
            RL[1] += B-A;
            return RL;
        }

        if(B==1)
        {
            RL[0] += A-B;
            return RL;            
        }

            
        if(A<B)
        {
            B = B-A;
            RL[1]++;
        }
        else
        {
            A =A-B;
            RL[0]++;
        }
        // printf("%d %d\n", A, B);
    }
}

int main(void)
{
    int A, B, i, j;
    int *RL;
    scanf("%d %d", &A, &B);

    RL = tree(A, B);

    printf("%d %d\n", RL[0], RL[1]);

    return 0;
}

/*
                  (1,1)
        (2,1)                (1,2)
   (3,1)     (2,3)      (3,2)      (1,3)
(4,1)(3,4) (5,3)(2,5) (5,2)(3,5) (4,3)(1,4)
(5,1)(4,5)


(3,5)
(3,2)
(1,2)
(1,1)

*/