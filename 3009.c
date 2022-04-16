#include <stdio.h>

int main(void)
{
    int i, j, squre[2][4], t[2][2]={0,};
    
    for(i=0; i<3; i++)
        scanf("%d %d", &squre[0][i], &squre[1][i]);
    
    for(i=0; i<2; i++)
    {
        t[0][0] = squre[i][0];
        t[0][1]++;

        for(j=1; j<3; j++)
        {
            if(t[0][0] == squre[i][j])
            {
                t[0][1]++;   
            }
            else
            {
                t[1][0] = squre[i][j];
                t[1][1]++;                
            }
        }


        if(t[0][1] == 1)
        {
            squre[i][3] = t[0][0];
        }
        else
        {
            squre[i][3] = t[1][0];
        }

        t[0][1] = t[1][1] = 0;
    }


    printf("%d %d\n", squre[0][3], squre[1][3]);

    return 0;
}