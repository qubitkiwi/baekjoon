#include <stdio.h>

int fec(int N)
{
    if(N < 3)
        return N?N:1;
    
    return N*fec(N-1);
}

int main(void)
{
    int N, anw;
    scanf("%d", &N);
    
    anw = fec(N);
    printf("%d\n", anw);

    return 0;
}