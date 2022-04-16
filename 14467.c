#include <stdio.h>

int main(void)
{
    int i, T, tc, num, t, cnt=0;
    int cow[10][2]={0, };

    scanf("%d", &T);

    for(tc=0; tc<T; tc++)
    {
        scanf("%d %d", &num, &t);

        if(cow[num-1][0]==0)
        {
            cow[num-1][0]++;
            cow[num-1][1] = t;
        }
        else if(cow[num-1][1] != t)
        {
            cow[num-1][0]++;
            cow[num-1][1] = t;
            cnt++;
        }
    }
        
    printf("%d\n", cnt);

    return 0;
}