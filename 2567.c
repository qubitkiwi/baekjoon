#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j, k, sum=0;
    int x_max, y_max;
    scanf("%d", &N);

    int paper[N][2];

    for(i=0; i<N; i++)
    {
        scanf("%d %d", &paper[i][0], &paper[i][1]);
    }

    x_max = paper[0][0];
    y_max = paper[0][1];

    for(i=1; i<N; i++)
    {
        if(x_max < paper[i][0])
        {
            x_max = paper[i][0];
        }
        if(y_max < paper[i][1])
        {
            y_max = paper[i][1];
        }
    }
    
    int arr[x_max+10][y_max+10];

    for(i=0; i<x_max+10; i++)
    {
        for(j=0; j<y_max+10; j++)
        {
            arr[i][j]=0;
        }
    }


    for(i=0; i<N; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<10; k++)
            {
                arr[paper[i][0]+j][paper[i][1]+k]=1;
            }
        }
    }

    for(i=0; i<x_max+10; i++)
    {
        for(j=0; j<y_max+10; j++)
        {
            printf("%d ", arr[i][j]);
            sum += arr[i][j];
        }
        printf("\n");
    }

    printf("%d\n", sum);

    return 0;
}