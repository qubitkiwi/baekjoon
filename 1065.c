#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) 
        return -1; 
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int han(int n)
{
    int i, t;
    char a[6];

    sprintf(a, "%d", n);
    qsort(a, strlen(a), sizeof(char), compare);

    t = a[1] - a[0];
    for(i=1; i<strlen(a)-1; i++)
    {
        if(t != a[i+1] - a[i])
            return 0;
        t = a[i+1] - a[i];
    }

    return 1;
}

int main(void)
{
    int N, i, j, anw=0;
    scanf("%d", &N);

    if(N<100)
        anw = N;
    else
    {
        anw = 99;

        for(i=100; i<=N; i++)
        {
            if(han(i) == 1)
                anw++;
        }
    }
    
    printf("%d\n", anw);

    return 0;
}