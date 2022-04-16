#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int N, i, j;
    int avg, median, range, sum = 0;
    int mode[2][2] = {0,};

    scanf("%d", &N);

    int arr[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    qsort(arr, N, sizeof(int), compare);


    avg = round(sum/N);
    median = arr[(int) N/2];
    range = arr[N-1] - arr[0];

    mode[0][0] = arr[0];
    mode[0][0] = 1;

    for(i=1; i<N; i++)
    {
        if(mode[0][0] == arr[i])
        {
            mode[0][1]++;    
        }
        else 
        {
            if(mode[0][1] > mode[1][1])
            {
                mode[1][0] = mode[0][0];
                mode[1][1] = mode[0][1];

                mode[0][0] = arr[i];
                mode[0][1] = 1;
            }

        }
    }



    printf("%d\n", avg);
    printf("%d\n", median);

    if(mode[0][1] == mode[1][1])
    {
        printf("%d\n", mode[1][0]);
    }
    else
    {
        printf("%d\n", mode[0][0]);
    }
    printf("%d\n", range);

    return 0;
}