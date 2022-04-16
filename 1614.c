#include <stdio.h>

int main(void)
{
    int N, cnt, i=1, anw=0;
    int up =1;
    scanf("%d", &N);
    scanf("%d", &cnt);

    while(1)
    {
        if(N == i)
            if(cnt--<=0)
                break;
        anw++;

        if(up)
        {
            i++;
            if(i>=5) up = 0;
        }
        else
        {
            i--;
            if(i<=1) up = 1;
        }
    }

    printf("%d\n", anw);

    return 0;
}