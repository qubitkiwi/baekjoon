#include <stdio.h>

int main(void)
{
    char room[7];
    int num[10] = {0,};
    int i, j, max, t;

    scanf("%s", room);

    for(i=0; room[i]; i++)
    {
        num[room[i] - '0']++;
    }


    if(num[6] != num[9])
    {
        t = num[6] + num[9];
        num[6] = (t%2==0) ? t/2 : t/2+1 ;
        num[9] = t/2;
    }

    max = num[0];

    for(i=1; i<10; i++)
    {
        if(max<num[i])
        {
            max = num[i];
        }
    }
    printf("%d\n", max);
    
    return 0;
}