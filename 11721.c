#include <stdio.h>

int main(void)
{
    int i;
    char A[101];
    scanf("%s", A);

    for(i=0; A[i]!=0; i++)
    {
        printf("%c", A[i]);
        if((i+1)%10==0)
        {
            printf("\n");
        }
    }
    
    return 0;
}