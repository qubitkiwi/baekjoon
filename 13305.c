#include <stdio.h>

int main(void)
{
    long long N, i, t, anw=0;
    scanf("%lld", &N);

    long long load[N-1];
    long long station[N];

    for(i=0; i<N-1; i++)
        scanf("%lld", &load[i]);
    
    for(i=0; i<N; i++)
        scanf("%lld", &station[i]);
    
        
    t = station[0];
    anw = station[0]*load[0];

    for(i=1; i<N-1; i++)
    {
        if(t>station[i])
            t = station[i];

        anw += load[i]*t;
    }

    printf("%lld\n", anw);

    return 0;
}