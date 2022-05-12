#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[102], buffer[100];
    int i, len, bp=0, chek;

    while(1)
    {
        fgets(s, 102, stdin);
        len = strlen(s);
        bp=chek=0;

        if(!strcmp(s, ".\n"))
            break;

        for(i=0; i<len; i++)
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
            printf("no\n");
        else
            printf("yes\n");

    }
    return 0;
}