#include <stdio.h>

int main(void)
{
    int i, j;
    char A[4], B[4];

    scanf("%s", A);
    scanf("%s", B);

    for(i=2; i>=0; i--)
    {
        if(A[i] > B[i])
        {
            for(j=2; j>=0; j--)
                printf("%c", A[j]);
            break;
        }
        else if(A[i] < B[i])
        {
            for(j=2; j>=0; j--)
                printf("%c", B[j]);
            break;
        }
    }

    return 0;
}