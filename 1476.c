#include <stdio.h>

int year_cal(int E, int S, int M)
{
    int i, j, k, year=0;

    if(E==1 && S==1 && M==1)
        return 1;

    while(1)
    {
        year++;
        if(year%15+1 == E && year%28+1 == S && year%19+1 == M)
        {
            return year+1;
        }
    }
}

int main()
{
    int E, S, M, year;
    int i, j, k;
    scanf("%d %d %d", &E, &S, &M);

    year = year_cal(E, S, M);

    printf("%d\n", year);
    return 0;
}

/* 
1 ≤ E ≤ 15
1 ≤ S ≤ 28
1 ≤ M ≤ 19

 */