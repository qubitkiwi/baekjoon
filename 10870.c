#include <stdio.h>

int fibo(int n)
{
    if(n<=0)
        return 0;
    else if(n<=2)
        return 1;
    
    return fibo(n-1)+fibo(n-2);
}

int main(void)
{
    int n, anw;
    scanf("%d", &n);
    anw = fibo(n);
    printf("%d\n", anw);

    return 0;
}

//0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
//