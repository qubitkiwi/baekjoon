#include <stdio.h>

int main(void)
{
    int i, t, cnt=0;
    int e[42] = {0,};

    for(i=0; i<10; i++)
    {
        scanf("%d", &t);
        e[t%42]++;
    }

    for(i=0; i<42; i++)
        if(e[i] > 0)
            cnt++;
    
    printf("%d\n", cnt);

    return 0;
}