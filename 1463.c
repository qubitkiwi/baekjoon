#include <stdio.h>

int main(void)
{
    int N, cnt=0;

    scanf("%d", &N);

    while(N != 1)
    {
        printf("%d   ", N);
        
        
        if(N%3==1)
        {
            N--;
            cnt++;
        }

        if(N%3==0)
        {
            N /=3;
            cnt++;
        }
        if(N%2==0)
        {
            N /= 2;
            cnt++;
        }
        
    }

    printf("%d\n", cnt);

    return 0;
}