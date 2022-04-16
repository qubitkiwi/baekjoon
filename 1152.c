#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000001];
    int i, n, start, end, t, anw = 0;

    fgets(s, 1000001, stdin);

    n = strlen(s)-1; //개행 제거

    for(start=0; s[start] == ' ' && start<n; start++);
    for(end=n-1; s[end] == ' ' && end>=0; end--);

    t = s[start];

    for(i=start+1; i<end; i++)
    {
        if(s[i] == ' ')
            anw++;
        t = s[i];
    }

    if(anw == 0)
    {
        if(s[start] >= 'A')
            anw++;
    }
    else
        anw++;
    
    printf("%d\n", anw);

    return 0;
}