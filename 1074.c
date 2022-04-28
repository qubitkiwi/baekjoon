#include <stdio.h>
#include <math.h>

int sol(int N, int r, int c)
{
    int z=0, threshold_x, threshold_y;
    threshold_x = threshold_y = pow(2, N-1);
    
    while(N--)
    {   
        if(r<threshold_x && c<threshold_y)
        {
            threshold_x -= pow(2, N-1);
            threshold_y -= pow(2, N-1);
        }
        else if(r<threshold_x && threshold_y<=c)
        {
            threshold_x -= pow(2, N-1);
            threshold_y += pow(2, N-1);
            z += pow(4, N)*1;
        }
        else if(threshold_x<=r && c<threshold_y)
        {
            threshold_x += pow(2, N-1);
            threshold_y -= pow(2, N-1);
            z += pow(4, N)*2;
        }
        else
        {
            threshold_x += pow(2, N-1);
            threshold_y += pow(2, N-1);
            z += pow(4, N)*3;
        }
    }
    return z;
}

int main()
{
    int N, r, c, Z;
    scanf("%d %d %d", &N, &r, &c);

    Z = sol(N, r, c);

    printf("%d\n", Z);
    return 0;
}   