#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i;
    char *s;
    int sum = 0;
    
    scanf("%d", &N);
    s = malloc((N+1)*sizeof(int));
    scanf("%s", s);
    for(i=0; i<N; i++)
    {
        sum += s[i] - '0';
    }

    printf("%d\n", sum);

    return 0;
}