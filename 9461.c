#include <stdio.h>

int main(void)
{
    int N, T, i;
    long P[101];

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    P[6] = 3;
    P[7] = 4;
    P[8] = 5;
    P[9] = 7;
    P[10] = 9;

    for(i=11; i<101; i++)
        P[i] = P[i-1] + P[i-5];

    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &i);
        printf("%ld\n", P[i]);
    }
    
    return 0;
}