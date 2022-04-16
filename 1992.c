#include <stdio.h>


int rec(int arr[], int N, int s)
{
    int i, j;
    int start[4] = {0, N/2, }

    if(N==1)
    {
        return 0;
    }
    printf("(");

    for(i=0; i<N/2; i++)
    {
        for(j=0; j<N/2; j++)
        {
            
        }
    }
    





    printf(")");
}


int main(void)
{
    int N, i, j;
    scanf("%d", &N);
    int arr[N][N];

    for(i=0; i<N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    
    




    return 0;
}