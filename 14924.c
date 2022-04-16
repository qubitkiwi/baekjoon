#include <stdio.h>

int main(void)
{
    int S, T, D, F;
    scanf("%d %d %d", &S, &T, &D);

    F = (D/(2*S))*T;
    printf("%d\n", F);

    return 0;
}