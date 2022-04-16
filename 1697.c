#include <stdio.h>

int V[100001] = {0,};
int queue[100001] = {0,};

int bfs(int N, int M)
{
    int max = 100001;
    int f, r, num, i;

    f=r=num =0;
    queue[r++] = N;
    V[N] = 1;
    r %= max;
    num++;

    while(num)
    {
        i = queue[f++];
        f %= max;
        num--;

        if(i==M)
        {
            return V[i];
        }

        if(0<=2*i && 2*i<100001)
        {
            if(V[2*i]==0)
            {
                queue[r++] = 2*i;
                V[2*i] = V[i]+1;
                r %= max;
                num++;
            }
        }    
        if(0<=i-1 && i-1<100001)
        {
            if(V[i-1]==0)
            {
                queue[r++] = i-1;
                V[i-1] = V[i]+1;
                r %= max;
                num++;            
            }
        }
        if(0<=i+1 && i+1<100001)
        {
            if(V[i+1]==0)
            {
                queue[r++] = i+1;
                V[i+1] = V[i]+1;
                r %= max;
                num++;            
            }
        }
    }
}

int main(void)
{
    int N, M, s;
    scanf("%d %d", &N, &M);

    s = bfs(N, M);

    printf("%d\n", s-1);

    return 0;
}