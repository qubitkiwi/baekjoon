#include <stdio.h>

int main(void)
{
    int A[50][3]={0,};
    int N, i, j, a, b, t[2];

    scanf("%d", &N);

    for(a=0; a<N; a++)
    {
        scanf("%d %d", &i, &j);
        A[a][0] = i;
        A[a][1] = j;
    }

        for(i=0; i<N; i++)
            printf("%d ", A[i][2]);
        printf("\n");

    A[0][2] = 1;

    t[0] = A[0][0];
    t[1] = A[0][1];
    t[2] = A[0][2];


    for(i=1; i<N; i++)
    {
        if(t[0] < A[i][0] && t[1] < A[i][1])
        {
            A[i][2] = t[2];
            for(j=i-1; j>=0; j--)
            {
                if(t[2] >= A[j][2])
                {
                    A[j][2]++;
                }
            }
        }
        else if(t[0] < A[i][0] || t[1] < A[i][1])
        {
            A[i][2] = t[2];
            for(j=i; j>=0; j--)
            {
                if(t[2] < A[j][2])
                {
                    A[j][2]++;
                }
            }
        }
        else
        {
            A[i][2] = i+1;
        }

        t[0] = A[i][0];
        t[1] = A[i][1];
        t[2] = A[i][2];

        for(j=0; j<N; j++)
            printf("%d ", A[j][2]);
        printf("\n");
    }

    
    for(i=0; i<N; i++)
        printf("%d ", A[i][2]);
    printf("\n");
    return 0;
}