#include <stdio.h>

int main(void)
{
    int N, M, i, j, k;
    char s[21];

    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        scanf("%d", &M);
        scanf("%s", s);

        for(j=0; s[j] != '\0'; j++)
        {
            for(k=0; k<M; k++)
            {
                printf("%c", s[j]);
            }
        }
        printf("\n"); 
    }
    return 0;
}