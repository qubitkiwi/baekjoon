#include <stdio.h>
#include <string.h>

int main(void)
{
    char cryp[100001];
    int aph[26];
    int i, N, t, chek;

    scanf("%d", &N);
    
    while(N--)
    {
        chek = 1;
        scanf("%s", cryp);

        for(i=0; i<26; i++)
            aph[i] = 0;
        
        for(i=0; cryp[i] ; i++)
        {
            t = cryp[i]-'A';
            aph[t]++;
            if(aph[t]%3 == 0)
            {
                if(cryp[i] == cryp[i+1])
                {
                    i++;
                }
                else
                {
                    chek = 0;
                    break;
                }
            }
        }

        if(chek==0)
            printf("FAKE\n");
        else
            printf("OK\n");
    }
    return 0;
}