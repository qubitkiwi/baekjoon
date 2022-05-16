#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j, max, next, before, chek=0;
    scanf("%d %d", &N, &M);
    
    for(i=0; i<M; i++)
    {
        scanf("%d", &max);

        scanf("%d", &before);
        for(j=1; j<max; j++)
        {
            scanf("%d", &next);
            if(before < next)
                chek = 1;
            before = next;
        }
    }

    if(chek == 0)
        printf("Yes\n");    
    else
        printf("No\n");
    
    return 0;
}

/* 

6 3
2
6 1
2
3 2
2
5 4
Yes

6 3
2
6 1
2
3 2
2
4 5
No


3 2
2
3 1
1
2
Yes

3 2
2
1 3
1
2
No
 */