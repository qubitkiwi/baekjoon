#include <stdio.h>

void print(int *arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");    
}

int chek(int *arr, int N)
{
    for (int i = 0; i < N; i++)
        if(arr[i] > arr[i+1])
            return 1;

    return 0;
}

int main(void)
{
    int i, j, k, t, wood[5];

    for(i=0; i<5; i++)
        scanf("%d", &wood[i]);
    
    while(chek(wood, 5))
    {
        for(i=0; i<4; i++)
        {
            if(wood[i] > wood[i+1])
            {
                t = wood[i];
                wood[i] = wood[i+1];
                wood[i+1] = t;

                print(wood, 5);
            }
        }   
    }
    
    return 0;
}