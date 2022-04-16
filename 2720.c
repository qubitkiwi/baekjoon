#include <stdio.h>

int main(void)
{
    int T, tc, N, i, j;
    int m[4] = {25, 10, 5, 1};
    int anw[4] = {0, 0, 0, 0};

    scanf("%d", &T);

    for(tc=0; tc<T; tc++)
    {


        scanf("%d", &N);
        
        for(i=0; i<sizeof(m)/sizeof(int); i++)
        {
            if(N/m[i]>0)
            {
                anw[i] = N/m[i];
                N %= m[i];            
            }
        }

        for(i=0; i<sizeof(anw)/sizeof(int); i++)
        {
            printf("%d ", anw[i]);
        }
        printf("\n");

        for(i=0; i<sizeof(anw)/sizeof(int); i++)
        {
            anw[i] = 0;
        }
        
    }
    return 0;
}