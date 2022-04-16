#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M, i, j, k;
    scanf("%d", &N);
    
    int sw[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &sw[i]);
    }

    scanf("%d", &M);
    int stud[M][2];
    for(i=0; i<M; i++)
    {
        scanf("%d %d", &stud[i][0], &stud[i][1]);
    }

    for(i=0; i<M; i++)
    {
        if(stud[i][0] == 1) //man
        {
            for(j=stud[i][1]-1; j<N; j+=stud[i][1])
            {
                sw[j] = sw[j] ? 0:1;
            }
        }
        else//woman
        {
            k=1;
            j = stud[i][1] -1;
            sw[j] = sw[j] ? 0:1;

            while(j-k>=0 && j+k<N && sw[j-k] == sw[j+k])
            {  
                sw[j+k] = sw[j+k] ? 0:1;
                sw[j-k] = sw[j-k] ? 0:1;
                k++;
            }

        }
    }
    
    for(i=0; i<N; i++)
    {
        printf("%d ", sw[i]);
        if((i+1)%20==0)
        {
            printf("\n");
        }

    }

    return 0;   
}