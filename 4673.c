#include <stdio.h>

int d(int n)
{
    int i, sum = n;

    for(i=1; i<6; i++)
    {
        sum += n%10;
        n = n/10;
    }
    return sum;
}


int main(void)
{
    int n, i, t;
    int arr[10001] = {0, };




    for(i=1; i<10001; i++)
    {
        t = d(i);
        if(t<10001)
            arr[t] = 1;
    }

    for(i=1; i<10001; i++)
        if(arr[i] == 0)
            printf("%d\n", i);
    

    return 0;
}