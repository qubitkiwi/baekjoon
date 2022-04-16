#include <stdio.h>

int main(void)
{
    int i, j, t, anw, a[3];

    while(1)
    {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        
        if(a[0] == 0 && a[1] == 0 && a[2]== 0)
            break;

        for(i=0; i<3; i++)
        {
            for(j=2; j>=i; j--)
            {
                if(a[i] > a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }

        anw = a[2]*a[2] - a[1]*a[1] - a[0]*a[0];
        if(anw == 0)
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}