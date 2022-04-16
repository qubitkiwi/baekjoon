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
    int N, i, j, min[3], t;
    scanf("%d", &N);

    int arr[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    min[0] = abs(arr[0]+arr[N-1]);
    min[1] = 0;
    min[2] = N-1;

    i=0;
    j=N-1;

    while(i<j)
    {
        t = abs(arr[i]+arr[j]);

        if(min[0] > t)
        {
            min[0] = t;
            min[1] = i;
            min[2] = j;
        }

        if(min[0] == 0)
        {
            break;
        }

        if(abs(arr[i+1] + arr[j]) < abs(arr[i] + arr[j-1]))
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    printf("%d %d", arr[min[1]], arr[min[2]]);

    return 0;
}

/* 
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
    int N, i, j, min[3], t;
    scanf("%d", &N);

    int arr[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    min[0] = abs(arr[0]+arr[N-1]);
    min[1] = 0;
    min[2] = N-1;


    for(i=0; arr[i]<0; i++)
    {
        for(j=N-1; arr[j]>0; j--)
        {

            t = abs(arr[i] + arr[j]);

            if(min[0] > t)
            {
                min[0] = t;
                min[1]   = i;
                min[2] = j;
            }

            if(arr[i] + arr[j]<0)
            {
                break;
            }
        }
    }

    printf("%d %d", arr[min[1]], arr[min[2]]);

    return 0;
}

*/