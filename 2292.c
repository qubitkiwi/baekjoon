#include <stdio.h>

int main(void)
{
    int N, M, i=1, j=1;
    scanf("%d", &N);

    while(i<N)
        i += 6*j++;
    

    printf("%d\n", j);

    return 0;
}
/*
1           = 1
                    6
2~7         = 6
                    6
8~19        = 12
                    6
20~37       = 18
                    6
38~61       = 24
62~


*/