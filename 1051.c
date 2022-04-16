#include <stdio.h>

int main(void)
{
    int i, j, l, k, n, m, max=1, area;
    char arr[51][51];

    scanf("%d %d", &n, &m);

    for(i=0; i<n; i++)
        scanf("%s", arr[i]);
    
    for(i=0; i<n-1;  i++)
    {
        for(j=0; j<m-1; j++)
        {
            for(k=1; i+k<n && j+k<m; k++)
            {
                if(arr[i][j] == arr[i+k][j] && arr[i+k][j] == arr[i+k][j+k] && arr[i+k][j+k] == arr[i][j+k])
                {
                    area = (k+1)*(k+1);
                    if(max < area)
                    {
                        max = area;
                    }
                }
            }
        }
    }

    printf("%d\n", max);

    return 0;
}