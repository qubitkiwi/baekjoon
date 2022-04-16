#include <stdio.h>

int main(void)
{
    int T, i, j, cnt, total;
    char s[81];

    scanf("%d", &T);
    
    for(i=0; i<T; i++)
    {
        cnt=1;
        total =0;
        scanf("%s", s);

        for(j=0; s[j]; j++)
        {
            if(s[j] == 'O')
            {
                total += cnt++;
            }
            else
            {
                cnt = 1;
            }
        }
        printf("%d\n", total);

    }


    return 0;
}