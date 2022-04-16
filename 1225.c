#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j;
    long long anw=0;
    char A[10001], B[10001];
    
    scanf("%s", A);
    scanf("%s", B);

    for(i=0; i<strlen(A); i++)
        for(j=0; j<strlen(B); j++)
            anw += (A[i] - '0')*(B[j] - '0');

    printf("%lld\n", anw);
    return 0;
}