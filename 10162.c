#include <stdio.h>

int main(void)
{
    int T, i, j;
    int timmer[3] = {300, 60, 10};
    int time[3] = {0, };

    scanf("%d", &T);

    for(i=0; i<3; i++)
    {
        if(T/timmer[i]>0)
        {
            time[i] = T/timmer[i];
            T %= timmer[i];
        }
    }

    if(T==0)
    {
        for(i=0; i<3; i++)
        {
            printf("%d ", time[i]);
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}