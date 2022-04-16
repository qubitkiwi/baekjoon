#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101];
    int i, n, cnt=0;

    scanf("%s", s);

    n = strlen(s);

    for(i=0; i<n; i++)
    {
        if(s[i] == 'c')
        {
            if(i+1<n && s[i+1] == '=')
            {
                cnt++;
                i+=1;
                continue;
            }
            else if(i+1<n && s[i+1] == '-')
            {
                cnt++;
                i+=1;
                continue;
            }
            cnt++;
        }
        else if(s[i] == 'd')
        {
            if(i+1<n && s[i+1] == 'z')
            {
                if(i+2<n && s[i+2] == '=')
                {
                    cnt++;
                    i += 2;
                    continue;
                }
            }
            else if(i+1<n && s[i+1] == '-')
            {
                cnt++;
                i+=1;
                continue;
            }
            cnt++;
        }
        else if(s[i] == 'l' && i+1<n && s[i+1] == 'j')
        {
            cnt++;
            i+=1;
            continue;
        }
        else if(s[i] == 'n' && i+1<n && s[i+1] == 'j')
        {
            cnt++;
            i+=1;
            continue;
        }
        else if(s[i] == 's' && i+1<n && s[i+1] == '=')
        {
            cnt++;
            i+=1;
            continue;
        }
        else if(s[i] == 'z' && i+1<n && s[i+1] == '=')
        {
            cnt++;
            i+=1;
            continue;   
        }
        else
        {
            cnt++;
        }
    }

    printf("%d\n", cnt);


    return 0;
}