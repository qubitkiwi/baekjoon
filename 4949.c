#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101], buffer[100] = {0,};
    int i, n, bp, chek, end=1;

    while(1)
    {
        if(end == 1)
            bp = chek =0;

        fgets(s, 101, stdin);
        n = strlen(s);
        end = s[n-2] == '.';

        
        if(n==2 && s[0] == '.' && end == 0)
            break;

        

        for(i=0; s[i] != '.' && i<n-1 ; i++)
        {
            if(s[i] == '(' || s[i] == '[')
            {
                buffer[bp++] = s[i];
            }
            else if(s[i] == ')')
            {
                if(bp>0 && buffer[bp-1] == '(')
                {
                    bp--;
                }
                else
                {
                    chek = 1;
                    break;
                }
            }
            else if(s[i] == ']')
            {
                if(bp>0 &&buffer[bp-1] == '[')
                {
                    bp--;
                }
                else
                {
                    chek = 1;
                    break;
                }
            }
        }


        if(chek == 1 || bp != 0)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }

    }
    return 0;
}