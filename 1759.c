#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(char *)a;
    int num2 = *(char *)b;

    if (num1 < num2) 
        return -1; 
    
    if (num1 > num2)
        return 1;
    
    return 0;
}


int chek(char *S, int *A, int L)
{
    int i, j;
    char in[5] = {'a', 'e', 'i', 'o', 'u'};
    int k=0;

    for(i=0; i<L; i++)
    {
        for(j=0; j<5; j++)
        {
            if(S[A[i]] == in[j])
            {
                k++;
                break;
            }
        }
    }

    if(k>=1 && L-k>=2)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

int main(void)
{
    int L, C, i, j;
    scanf("%d %d", &L, &C);

    int A[L];
    char S[C];

    for(i=0; i<C; i++)
    {
        scanf(" %c", &S[i]);
    }

    for(i=0; i<L; i++)
    {
        A[i] = i;
    }


    qsort(S, C, sizeof(char), compare);

    if(chek(S, A, L))
    {
        for(i=0; i<L; i++)
        {
            printf("%c", S[A[i]]);
        }
        printf("\n");
    }

    while(A[0] < C-L)
    {

        if(A[L-1]+1 < L)
        {
            A[L-1]++;
        }
        else
        {
            for(i=L-1; i>=0; i--)
            {
                if(A[i] < C-L+i)
                {
                    A[i]++;
                    for(j=i; j<L; j++)
                    {
                        A[j+1] = A[j]+1;
                    }
                    break;
                }
            }
        }

        if(chek(S, A, L))
        {
            for(i=0; i<L; i++)
            {
                printf("%c", S[A[i]]);
            }
            printf("\n");
        }
    }
    return 0;
}
