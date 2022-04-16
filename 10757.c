#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char A[10002], B[10002], C[10003] = {0,};
    int n, m, i, j, T, d;
    
    scanf("%s", A);
    scanf("%s", B);

    n = strlen(A);
    m = strlen(B);

    d = abs(n-m);

    if(n >= m)
    {
        for(i=n-1; i>=d; i--)
        {
            T = A[i]+B[i-d] -'0'-'0';
            C[i+1] += T%10+'0';
            if(C[i+1] > '9')
            {
                C[i+1] = '0';
                C[i]++;
            }
            C[i] += T/10;
        }
        for(i=d-1; i>=0; i--)
        {
            T = A[i] -'0';
            C[i+1] += T%10+'0';
            if(C[i+1] > '9')
            {
                C[i+1] = '0';
                C[i]++;
            }
            C[i] += T/10;

        }

        if(C[0] != 0)
        {
            C[0] += '0';
            printf("%c", C[0]);

            for(i=1; i<=n; i++)
                printf("%c", C[i]);
        }
        else
        {
            for(i=1; i<=n; i++)
                printf("%c", C[i]);
        }
    
        printf("\n");
    }
    else
    {
        for(i=m-1; i>=d; i--)
        {
            T = A[i-d]+B[i] -'0'-'0';
            C[i+1] += T%10+'0';
            if(C[i+1] > '9')
            {
                C[i+1] = '0';
                C[i]++;
            }
            C[i] += T/10;

        }
        for(i=d-1; i>=0; i--)
        {
            T = B[i] -'0';
            C[i+1] += T%10+'0';
            if(C[i+1] > '9')
            {
                C[i+1] = '0';
                C[i]++;
            }
            C[i] += T/10;

        }

        if(C[0] != 0)
        {
            C[0] += '0';
            printf("%c", C[0]);

            for(i=1; i<=m; i++)
                printf("%c", C[i]);
        }
        else
        {
            for(i=1; i<=m; i++)
                printf("%c", C[i]);
        }
    
        printf("\n");
    }
    return 0;
}