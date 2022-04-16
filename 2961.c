#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,S,B;
    int i, j;
    int min, diff;

    scanf("%d", &N);

    int** taste = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) 
    { 
        taste[i] = (int*)malloc(sizeof(int) * 2);
        scanf("%d %d", &taste[i][0], &taste[i][1]);
    }


	bool** combination  = (bool**)malloc(sizeof(bool*) * N);
	for (i = 0; i < N; i++)
    {
		combination [i] = (bool*)malloc(sizeof(bool) * N);
	}

    



    for(i=0; i<N; i++)
    {
        for(j=N-1; j>i; j--)
        {
            diff = abs(taste[i][0]*taste[j][0] - taste[i][1]-taste[j][1]);
            if(diff < min)
            {
                printf("%d\n", diff);
                min = diff;
            }
        }
    }

    printf("%d\n", min);


    for (i = 0; i < n; i++) 
    {
		free(combination[i]);
	}
    free(combination);

    for (i = 0; i < n; i++) 
    {
		free(taste[i]);
	}
    free(taste);
    return 0;
}