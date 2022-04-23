#include <stdio.h>
#include <string.h>

int turn_off(char *lamp)
{
    int i, j, len, cnt=0;
    len = strlen(lamp);
    
    for (i=1; i<=len; i++)
    {
        if(lamp[i-1] == 'Y')
        {
            cnt++;
            for(j=i-1; j<len; j+=i)
            {
                if(lamp[j] == 'Y')
                    lamp[j] = 'N';
                else
                    lamp[j] = 'Y';
            }
        }
    }
    return cnt;
}

int main()
{
    char lamp[10001];
    int cnt;
    scanf("%s", lamp);

    cnt = turn_off(lamp);
    printf("%d\n", cnt);

    return 0;
}