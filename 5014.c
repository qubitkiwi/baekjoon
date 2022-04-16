#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int F, S, G, U, D, floor, chek=0;
    int *V, *queue;
    int f, r, num, max;

    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    V = (int *)malloc((F+1)*sizeof(int));
    queue = (int *)malloc((F+1)*sizeof(int));

    f=r=num=0;
    max = F+1;

    V[S] = 1;
    queue[r++] = S;
    num++;

    while(num)
    {
        floor = queue[f++];
        f %= max;
        num--;

        if(floor == G)
        {
            chek = 1;
            break;
        }

        if(floor+U <= F && V[floor+U] == 0)
        {
            V[floor+U] = V[floor]+1;
            queue[r++] = floor+U;
            r%=max;
            num++;
        }
        if(floor-D > 0 && V[floor-D] == 0)
        {
            V[floor-D] = V[floor]+1;
            queue[r++] = floor-D;
            r%=max;
            num++;
        }
    }

    if(chek)
        printf("%d\n", V[floor]-1);
    else
        printf("use the stairs\n");

        
    free(V);
    free(queue);

    return 0;
}