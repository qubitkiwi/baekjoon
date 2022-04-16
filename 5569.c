#include <stdio.h>

int V[3] = {0,};
int recode[100+100] = {0,};
int cnt = 0;

int dfs(int d, int *wh)
{
    int i, j;


    if(d == wh[1]+wh[2]-2 && V[1] == wh[1]-1 && V[2] == wh[2]-1)
    {
        for(i=0; i<d; i++)
            printf("%d ",recode[i]);
        printf("\n");
        cnt++;
        return 1;
    }

        //     int t[2] = {0,};

        // t[0] = recode[0];
        // for(i=1; i<d; i++)
        // {
        //     if(t[0] == recode[i])
        //     {
        //         t[1]++;
        //     }
        //     else if(i<2 && t[0] != recode[i] && t[1] < 1)
        //     {
        //         t[0] = recode[i];
        //         t[1] = 0;
        //     }
        //     else if(t[0] != recode[i] && t[1] < 1)
        //     {
        //         return 1;
        //     }
        //     else
        //     {
        //         t[0] = recode[i];
        //         t[1] = 0;
        //     }
        // }
        // printf("%d %d   ", V[1], V[2]);

        // for(i=0; i<d; i++)
        //     printf("%d ",recode[i]);
        // printf("\n");
    for(i=1; i<3; i++)
    {
        if(V[1] < wh[1] && V[2] < wh[2])
        {
            if(d>1 && d < wh[1]+wh[2]-2)
            {
                if(recode[d-1] == i ||recode[d-1] == recode[d-2])
                {
                    V[i]++;
                    recode[d] = i;
                    dfs(d+1, wh);
                    V[i]--;
                }
            }
            else
            {
                V[i]++;
                recode[d] = i;
                dfs(d+1, wh);
                V[i]--;
            }
        }
    }
}



int main(void)
{
    int w, h, anw;
    int wh[3];
    scanf("%d %d", &wh[1], &wh[2]);
    
    dfs(0, wh);

    printf("%d\n", cnt%100000);
    return 0;
}

/*
0 오른
1 위

3*4

2+3

0 0 1 1 1
0 1 1 1 0

1 0 0 1 1
1 1 0 0 1
1 1 1 0 0

x 00 x 11 x



0 0 0 1 1 1 1 * 5+4


0   1 11 111 
2   1 3   4   
22  3 6  10   







*/