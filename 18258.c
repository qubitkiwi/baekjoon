#include <stdio.h>
#include <string.h>

int main(void)
{
    int N, f, r, num, t, max = 2000000;
    int queue[2000000];
    char cmd[6];
    f=r=num = 0;

    scanf("%d", &N);

    while(N--)
    {
        scanf("%s", cmd);

        if(!strcmp(cmd, "push"))
        {
            scanf("%d", &t);
            queue[r++] = t;
            r %= max;
            num++;
            
        }
        else if(!strcmp(cmd, "pop"))
        {
            if(num==0)
            {
               t = -1;
            }
            else
            {
                t = queue[f++];
                f %= max;
                num--;
            }
            printf("%d\n", t);
        }
        else if(!strcmp(cmd, "size"))
        {
            printf("%d\n", num);
        }
        else if(!strcmp(cmd, "empty"))
        {
            t = num ? 0 : 1;
            printf("%d\n", t);
        }
        else if(!strcmp(cmd, "front"))
        {
            if(num) t = queue[f];
            else    t = -1;
            printf("%d\n", t);
        }
        else if(!strcmp(cmd, "back"))
        {
            if(num) t = queue[r-1];
            else    t = -1;
            printf("%d\n", t);
        }
    }

    return 0;
}
