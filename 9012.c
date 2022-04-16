#include <stdio.h>

int main(void)
{
    int T, N, i, j;
    char arr[51];

    scanf("%d", &N);


    for(T=0; T<N; T++)
    {
        scanf("%s", arr);

        j=0;
        for(i=0; arr[i] != 0; i++)
        {
            if(arr[i] == 40)
            {
                j++;
            }
            else if(arr[i] == 41)
            {   
                j--;
                if(j==-1)
                {
                    break;
                }
            }
        }

        if(j==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}