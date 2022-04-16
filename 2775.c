#include <stdio.h>
#include <stdlib.h>

int** emptysquare(int colum, int row)
{
    int** result = (int**)malloc(sizeof(int*) * colum);
    for(int i=0; i<colum; i++)
        result[i] = (int*)calloc(row, sizeof(int));
    return result;
}

void freesquare(int **arr, int colum)
{
    for(int i=0; i<colum; i++)
        free(arr[i]);
    free(arr);
    return ;
}


int** solution(int k, int n) 
{
    k = k+1;
    int i, j;
    int** answer = emptysquare(k, n);
    
    for(i=0; i<n; i++) answer[0][i] = i+1;
    for(i=0; i<k; i++) answer[i][0] = 1;


    for(i=1; i<k; i++)
        for(j=1; j<n; j++)
            answer[i][j] = answer[i-1][j] + answer[i][j-1];

    return answer;
}

int main(void)
{
    int T, tc, k, n, i, j;
    int **arr;

    scanf("%d", &T);

    for(tc=0; tc<T; tc++)
    {
        scanf("%d %d", &k, &n);
        arr = solution(k, n);
        printf("%d\n", arr[k][n-1]);
        freesquare(arr, k);
    }    
    return 0;
}

/*


1 2 3  4  5  6  7 8 9 10
1 3 6 10 15 21 28
1
1
1




01 = 1
02 = 2
03 = 3
04 = 4

101 = 1
102 = 1+2 =3
103 = 1+2+3 = 6
104 = 1+2+3+4 = 10
105 = 1+2+3+4+5 = 15
106 = 1+2+3+4+5+6 = 21

201 = 1
202 = 1+3 = 4;
203 = 1+3+6 = 10;
204 = 1+3+6+10 = 20
205 = 1+3+6+10+15 = 35

201 = 1
202 = 1+(1+2) = 4;
203 = 1+(1+2)+(1+2+3) = 10;
204 = 1+(1+2)+(1+2+3)+(1+2+3+4) = 20
205 = 1+(1+2)+(1+2+3)+(1+2+3+4)+(1+2+3+4+5) = 35



301 = 1
302 = 1+4 = 5
303 = 1+4+10 = 15
304 = 1+4+10+20 = 35
305 = 1+4+10+20+35 = 70

301 = 1
302 = 1+(1+(1+2)) = 5
303 = 1+(1+(1+2))+(1+(1+2)+(1+2+3)) = 15
304 = 1+(1+(1+2))+(1+(1+2)+(1+2+3))+(1+(1+2)+(1+2+3)+(1+2+3+4)) = 35
305 = 1+(1+(1+2))+(1+(1+2)+(1+2+3))+(1+(1+2)+(1+2+3)+(1+2+3+4))+(1+(1+2)+(1+2+3)+(1+2+3+4)+(1+2+3+4+5)) = 70

401 = 1
402 = 1+5 = 6

401 = 1
402 = 1+(1+(1+(1+2))) = 6

k0n = 1*k+2(k-1)+ 3(k-2)... n*(k-k+1)

n(n+1)/2

*/