#include <stdio.h>

int main(void)
{
    int N, d, k, c;
    int i, k_p, f, r, max_kind, now_kind = 0;
    int sushi[3000001];
    int kind[3001] = {0,};

    f = r = 0;

    scanf("%d %d %d %d", &N, &d, &k, &c);

    for(i=0; i<N; i++)
        scanf("%d", &sushi[i]);
    
    for(r=0; r<k; r++)
    {
        if(kind[sushi[r]] == 0)
            now_kind++;
        
        kind[sushi[r]]++;
    }

    if(kind[c]==0 && max_kind < now_kind +1)
        max_kind = now_kind + 1;
    else if(max_kind < now_kind)
        max_kind = now_kind;

    r %= N;

    for(i=0; i<=N; i++)
    {
        if(kind[sushi[r]] == 0)
            now_kind++;

        kind[sushi[r]]++;

        kind[sushi[f]]--;
        if(kind[sushi[f]] == 0)
            now_kind--;

        if(kind[c]==0 && max_kind < now_kind +1)
            max_kind = now_kind + 1;
        else if(max_kind < now_kind)
            max_kind = now_kind;

        r++; r %= N;
        f++; f %= N;        
    }


    printf("%d\n", max_kind);

    return 0;
}