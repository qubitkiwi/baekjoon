#include <stdio.h>

int main(void)
{
    int n, i, j, k;
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        for(j=0; j<i; j++)
            printf(" ");

        printf("*");
        for(j=0; j<i; j++)
            printf("*");
    }   

    return 0;
}