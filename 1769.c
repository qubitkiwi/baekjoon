#include <stdio.h>

int main(void)
{
    int x, i, j, cnt=0, sum=0;
    scanf("%d", &x);

    printf("%d ", x%10);

    for(i=10; i<x; i*=10)
    {
        printf("%d ", (x/i)%i);
        // sum += (x%i)/i;
    }
    printf("\n");

    return 0;
}