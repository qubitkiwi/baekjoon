#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, k, n, m;
    char key[11];
    char ciphrt[101];
    char decipher[11][10];
    char T;

    scanf("%s", key);
    scanf("%s", ciphrt);

    n = strlen(key);
    m = strlen(ciphrt);

    for(i=0; i<n; i++)
        decipher[0][i] = key[i];
    
    for(i=0; i<m; i++)
    {
        j = i/n+1;
        decipher[j][i%n] = ciphrt[i];
    }
    
    for(i=0; i<= m/n; i++)
    {
        for(j=0; j<n; j++)
            printf("%c ", decipher[i][j]);
        printf("\n");
    }
    printf("\n");

    for(i=0; i<n; i++)
    {
        for(j=n-1; i<j; j--)
        {
            if(decipher[0][j-1] > decipher[0][j])
            {
                for(k=0; k<=m/n; k++)
                {
                    T = decipher[k][j-1];
                    decipher[k][j-1] = decipher[k][j];
                    decipher[k][j] = T;
                }
            }
        }
    }

   
    for(i=0; i<= m/n; i++)
    {
        for(j=0; j<n; j++)
            printf("%c ", decipher[i][j]);
        printf("\n");
    }

    for(j=0; j<n; j++)
        for(i=1; i<= m/n; i++)
            printf("%c", decipher[i][j]);
    printf("\n");
    
    return 0;
}