#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 > num2)
        return -1;
    if (num1 < num2)
        return 1;    
    return 0;
}

int main()
{
    int N, i, t, dasam, *candi, cnt=0;
    scanf("%d", &N);

    candi = (int *)calloc(N-1, sizeof(int));

    scanf("%d", &dasam);
    for(i=0; i<N-1; i++)
        scanf("%d", &candi[i]);

    qsort(candi, N-1, sizeof(int), compare);

    while(dasam <= candi[0])
    {
        dasam++;
        candi[0]--;
        qsort(candi, N-1, sizeof(int), compare);
        cnt++;
    }

    printf("%d\n", cnt);

 
    return 0;
}