#include <stdio.h>

int main(void)
{
    int i, j, k, t, wood[5];

    for(i=0; i<5; i++)
    {
        scanf("%d", &wood[i]);
    }
    

    do
    {
        for(j=0; j<4; j++)
        {
            if(wood[j] > wood[j+1])
            {
                t = wood[j];
                wood[j] = wood[j+1];
                wood[j+1] = t;
                break;
            }
        }


        for(k=0; k<5; k++)
        {
            printf("%d ", wood[k]);
        }
        printf("\n");

    }while(wood[0] > wood[1] || wood[1] > wood[2] || wood[2] > wood[3] || wood[3] > wood[4] );


    return 0;
}