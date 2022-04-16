#include <stdio.h>

int main(void)
{
    int n, i=0, j=0;
    scanf("%d", &n);

    while(i<n)
        i += (j++ +1);

    if(j%2==1)
        printf("%d/%d\n", i-n+1, j-i+n);
    else
        printf("%d/%d\n", j-i+n, i-n+1);
    return 0;
}

/*

1       1/1

2       1/2
3       2/1

4       3/1
5       2/2
6       1/3

7       1/4
8       2/3
9       3/2
10      4/1


9 10 4

3/2

3 = 4-9+10

*/