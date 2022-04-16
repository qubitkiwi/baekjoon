#include <stdio.h>

int main(void)
{
    char s[101];
    int alphabet[26];
    int i;

    for(i=0; i<26; i++)
    {
        alphabet[i] = -1;
    }
    

    scanf("%s", s);
    for(i=0; s[i] != 0; i++)
    {
        if(alphabet[s[i]-'a'] == -1)
        {
            alphabet[s[i]-'a'] = i;
        }
        
    }
    
    for(i=0; i<26; i++)
    {
        printf("%d ", alphabet[i]);
    }
    printf("\n");

    return 0;
}
