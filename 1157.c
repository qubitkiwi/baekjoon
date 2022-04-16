#include <stdio.h>
#include <string.h>

int main(void)
{  
    int i, n, aph[26], max[2][2] = {0, };
    char s[1000001];
    scanf("%s", s);
    n = strlen(s);

    for(i=0; i<n; i++)
    {
        if(s[i] <= 'Z')
            aph[s[i] - 'A']++;
        else
            aph[s[i] - 'a']++;
    }

    
    for(i=0; i<26; i++)
    {
        if(max[0][0] < aph[i])
        {
            max[0][0] = aph[i];
            max[0][1] = i;
        }
        else if(max[0][0] != 0 && max[0][0] == aph[i])
        {
            max[1][0] = aph[i];
            max[1][1] = i;
        }
    }

    if(max[0][0] == max[1][0])
        printf("?\n");
    else
        printf("%c\n", 'A'+ max[0][1]);

    return 0;
}