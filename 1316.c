#include <stdio.h>
#include <string.h>

int group_word_cheker(char *s, int n)
{
    int i, aph[26] = {0,};
    char c;

    c = s[0];
    i=0;
    while(i<n)
    {
        aph[s[i]-'a'] = 1;
        while(s[i] == c)
            i++;
            
        if(aph[s[i]-'a'] == 1)
            return 0;
        c = s[i];

    }
    return 1;
}


int main(void)
{
    int T, tc, i, j, n, cnt=0;
    char word[101];

    scanf("%d", &T);

    for(tc=0; tc<T; tc++)
    {
        scanf("%s", word);
        n = strlen(word);

        if(group_word_cheker(word, n))
           
            cnt++;        
    }
    printf("%d\n", cnt);

    return 0;
}