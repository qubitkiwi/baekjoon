#include <stdio.h>

int main(void)
{
    int H, M, A;

    scanf("%d %d", &H, &M);
    scanf("%d", &A);

    M += A;
    H += M/60;
    M %= 60;
    H %= 24;

    printf("%d %d\n", H, M);

    return 0;
}