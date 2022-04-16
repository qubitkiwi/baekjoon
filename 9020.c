#include <stdio.h>

int main(void)
{
    int T, n, i, j, t[2], chek, k=0;
    int p[10001]={0, };
    int p_num[10001];

    p[1] = 1;
    
    scanf("%d", &T);
        
    for(i=2; i<10001; i++)
    {
        if(p[i] == 1)
            continue;
        
        p_num[k++] = i;

        for(j=2; j*i<10001; j++)
            p[i*j] = 1;
    }

    while(T--)
    {
        scanf("%d", &n);
        chek = 0;

        for(i=k-1; i>=0; i--)
        {
            for(j=i; j < k; j++)
            {
                if(n == p_num[i] + p_num[j])
                {
                    t[0] = p_num[i];
                    t[1] = p_num[j];
                    chek = 1;
                    break;
                }
                if(n < p_num[i] + p_num[j]+1) break;
            }
            if(chek) break;
        }

        printf("%d %d\n", t[0] , t[1]);
    }

    return 0;
}