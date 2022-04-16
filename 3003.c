#include <stdio.h>

int main(void)
{
    int A[6] = {1, 1, 2, 2, 2, 8};
    int i, t;

    for(i=0; i<6; i++)
    {
        scanf("%d", &t);
        printf("%d ", A[i] - t);
    }
    printf("\n");
    
    return 0;
}