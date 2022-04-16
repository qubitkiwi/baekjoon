#include <stdio.h>

int recode[9];
int V[9];

void tracking(int s, int d, int n, int m)
{
    int i;

    if(d == m)
    {
        for(i=0; i<m; i++)
            printf("%d ", recode[i]);
        printf("\n");
        return ;
    }

    for(i=s; i<=n; i++)
    {
        if(!V[i])
        {
            V[i] = 1;
            recode[d] = i;
            tracking(i+1, d+1, n, m);
            V[i] = 0;
        }
    }
}

int main(void)
{
    int N, M, i, j;
    scanf("%d %d", &N, &M);

    tracking(1, 0, N, M);
    return 0;
}

/*

4 2

1 2
1 3
1 4
2 3
2 4
3 4

1 1 0 0
1 0 1 0
1 0 0 1
0 1 1 0
0 1 0 1
0 0 1 1


1 2 0 0
1 0 2 0
1 0 0 2

2 1 0 0
0 1 2 0
0 1 0 2

2 0 1 0
0 2 1 0
0 0 1 2 

2 0 0 1
0 2 0 1
0 0 2 1



4 3
1 2 3 0
1 2 0 3
1 0 2 3
0 1 2 3



*/