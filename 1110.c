#include <stdio.h>

int main(void)
{
    int N, A, B, C, D=0, tmp;
    scanf("%d", &N);
    tmp = N;

    do
    {
        A = tmp/10;
        B = tmp%10;

        C = A+B;
        tmp = B*10 + C%10;
        D++;

    }while(N != tmp);

    printf("%d\n", D);

    return 0;
}