#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) 
        return -1; 
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(void)
{
    int x, N, i, j, t, chek=0;


    while(scanf("%d", &x) ==1)
    {
        scanf("%d", &N);

        x = x*10000000;

        int rego[N];
        for(i=0; i<N; i++)
        {
            scanf("%d", &rego[i]);
        }

        qsort(rego, N, sizeof(int), compare);

        i=0;
        j=N-1;
        chek=0;

        while(i<j)
        { 
            t = rego[i]+rego[j];
            if(t == x)
            {
                chek = 1;
                break;
            }

            if(t > x)
            {
                j--;
            }

            if(t < x)
            {
                i++;
            }
        }

        if(chek)
        {
            printf("yes %d %d\n", rego[i], rego[j]);
        }
        else
        {
            printf("danger\n");
        }
    }

    return 0;
}