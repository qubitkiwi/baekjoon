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

int main(void)
{
    int i, N;
    char t;
    char arr1[11];
    int arr2[11];
    scanf("%s", arr1);

    for(i=0; arr1[i]; i++)
    {
        N = i;
        arr2[i] = arr1[i] - '0';
    }

    qsort(arr2, N+1, sizeof(int), compare);


    for(i=0; i<N+1; i++)
        printf("%d", arr2[i]);
    
    printf("\n");

    return 0;
}