#include <stdio.h>

int main(void)
{
    long A, B, C, anw;
    scanf("%ld %ld %ld", &A, &B, &C);
    
    if(B >= C)
        printf("-1\n");
    else
        printf("%ld\n", A/(C - B)+1);

    return 0;
}