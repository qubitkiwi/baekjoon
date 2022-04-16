#include <stdio.h>

int pow1(int a, int b)
{
    int c=1;
    while(b--)
    {
        c = c*a;
    }
    return c;
}


int main()
{
    int N, r, c;
    int i, j, x, y;
    int Z;

    scanf("%d %d %d", &N, &r, &c);

    x = pow1(2, N)/2;
    y = x;
    Z = 0;

    while(N--)
    {
        i = pow1(2, N)/2;
        j = pow1(4, N);

        if(r < x && c < y)//2사분면
        {
            x -= i;
            y -= i;
        }
        else if(r < x && c >= y) //1사분면
        {
            x -= i;
            y += i;
            Z += j;

        }
        else if(r >= x && c < y) //3사분면
        {
            x += i;
            y -= i;
            Z += j*2;
        }
        else //4사분면
        {
            x -= i;
            y -= i;
            Z += j*3;
        }

    }
    printf("%d\n", Z);

    return 0;
}   