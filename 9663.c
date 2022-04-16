#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

int** empty_square(int size)
{
    int** result = (int**)malloc(sizeof(int*) * size);
    for(int i=0; i<size; i++)
        result[i] = (int*)calloc(size, sizeof(int));
    return result;
}

void free_square(int **arr)
{
    int i, size;
    size = sizeof(arr)/sizeof(int);
    for(int i=0; i<size; i++)
        free(arr[i]);
    free(arr);
}

int is_p(int x, int y, int N, int **map)
{
    int i;

    for(i=0; i<N; i++)
        if(map[i][x] == 1)
            return 0;

    // for(i=0; y+i<N && x+i<N; i++)
    //     if(map[y+i][x+i] == 1)
    //         return 0;
    for(i=0; 0<=y-i && 0<=x-i; i++)
        if(map[y-i][x-i] == 1)
            return 0;

    for(i=0; 0<=y-i && x+i<N; i++)
        if(map[y-i][x+i] == 1)
            return 0;
    // for(i=0; y+i<N && 0<=x-i; i++)
    //     if(map[y+i][x-i] == 1)
    //         return 0;

    return 1;
}

void dfs(int d, int N, int **map)
{
    int i;

    if(d == N)
    {
        cnt++;
        return ;
    }


    for(i=0; i<N; i++)
    {
        if(is_p(i, d, N, map))
        {
            map[d][i] = 1;
            dfs(d+1, N, map);
            map[d][i] = 0;
        }
    }
}


int main(void)
{
    int N, i, j;
    int **map, **V;
    scanf("%d", &N);

    map = empty_square(N);

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            map[i][j] = 0;

    dfs(0, N, map);
    printf("%d\n", cnt);

    free_square(map);
    return 0;
}





/*

1. 모든 경로를 다 이동후 확인
    검사를 할려면 map을 매번 초기화 해야되나?
2. 경로마다 검사

3. 조합 + 경로마다 검사





*/