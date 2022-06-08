#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_I(char *M, int start, int len)
{
    if(start > len)
        return -1;

    int idx = start;
    while(idx < len && M[idx] != 'I')
        idx++;
    
    if(idx >= len)
        return -1;
    return idx;
}


int main()
{
    int N, S, t, prov=0, next=0, cnt=0;
    scanf("%d %d", &N, &S);

    char M[S+2];
    scanf("%s", M);

    prov = find_I(M, prov, S);
    while( prov >= 0)
    {
        t=0;
        next = find_I(M, prov+1, S);

        while (next >= 0)
        {            
            if(next - prov == 2)
                t++;
            else
                break;
            
            prov = next;
            next = find_I(M, prov+1, S);
        }

        if(t-N+1 > 0)
            cnt += t-N+1;

        prov = find_I(M, prov+1, S);    
    }

    printf("%d\n", cnt);

    return 0;
}