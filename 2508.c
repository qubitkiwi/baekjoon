#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int r, c, T, test_case;
    int i, j;
    int cnt=0;
    // char candi[401][401];
    

    scanf("%d", &T);
    for(test_case=0; test_case<T; test_case++)
    {
        scanf("%d %d", &r, &c);
        // char (*candi)[c] = (char (*)[c])malloc(r * c * sizeof(char));
        char candi[r][c];

        for(i=0; i<r; i++)
        {
            scanf("%s", candi[i]);   
        }
        

        cnt=0;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(candi[i][j] == '>')
                {
                    if(j+1<c && candi[i][j+1] == 'o' && j+2<c && candi[i][j+2] == '<')
                    {
                        cnt++;
                    }
                }
                else if(candi[i][j] == 'v')
                {
                    if(i+1<r && candi[i+1][j] == 'o' && i+2<r && candi[i+2][j] == '^')
                    {
                        cnt++;
                    }
                }
                
            }
        }

        printf("%d\n", cnt);
        
        // free(candi);

    }
    return 0;
}