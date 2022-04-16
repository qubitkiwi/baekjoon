#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[16];
    int i, j, n, anw=0;
    scanf("%s", s);

    n = strlen(s);

    for(i=0; i<n; i++)
    {
        if(s[i] <= 'O')
        {
            anw += (s[i] - 'A')/3 +3;
        }
        else if(s[i] <= 'S')
        {
            anw += 8;
        }
        else if(s[i] <= 'V')
        {
            anw += 9;
        }
        else
        {
            anw += 10;
        }
    }
    printf("%d\n", anw);

    return 0;
}