#include <stdio.h>

int main(void)
{
    int A, B, V, diff, C=0;
    int day=1;
    scanf("%d %d %d", &A, &B, &V);

    V -= A;
    diff = A-B;

    C = (V/diff)*diff;
    day += V/diff;

    while(C < V)
    {
        C += diff;
        day++;
    }
    printf("%d\n", day);

    return 0;
}