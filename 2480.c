#include <stdio.h>

int main(void)
{
    int a[3];
    int i, j, max, momey=0;
    int same=0;

    for(i=0; i<3; i++)
    {
        scanf("%d", &a[i]);
    }

    if(a[0]==a[1] && a[1] == a[2])
    {
        momey = 10000+a[0]*1000;
    }
    else if(a[0]==a[1] || a[0]==a[2])
    {
        momey = 1000+a[0]*100;
    }
    else if(a[1]==a[2] )
    {
        momey = 1000+a[1]*100;
    }
    else
    {
        max = a[0];
        if(a[1]> max)
        {
            max = a[1];
        }
        if(a[2]> max)
        {
            max = a[2];
        }

        momey = max*100;
    }
    
    printf("%d\n", momey);

    return 0;
}