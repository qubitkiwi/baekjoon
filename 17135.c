#include <stdio.h>


int org_map[16][15] = {0,};
int map[16][15];
int aloow_set[3];
int N, M, D, max = 0;

void attck(int x, int y);
int chek();
void allow_setting(int s, int d);

void arr_print()
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

int chek(int n)
{
    int i, j, num=0;
    // arr_print();
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            if(map[i][j] >1)
            {
                num++;
                map[i][j] = 0; 
                // arr_print();
            }
        }
    }
    // arr_print();

    for(i=0; i<M; i++)
    {
        map[n-1][i] = 0;
    }


    return num;
}


void allow_setting(int s, int d)
{
    int i, j, k, l, num;

    if(d==3)
    {
        // printf("set : %d %d %d\n", aloow_set[0], aloow_set[1], aloow_set[2]);

        for(i=0; i<N; i++)
            for(j=0; j<M; j++)
                map[i][j] = org_map[i][j];

        num = 0;
        for(i=N; 0<i; i--)
        {
            for(j=0; j<3; j++)
            {
                // for(k=0; k<N+1; k++)
                //     for(l=0; l<M; l++)
                //         V[k][l] = 0;

                attck(i, aloow_set[j]);
                
            }

            num += chek(i);
        }

        if(max < num)
            max = num;

        // printf("%d\n", num);
        // printf("\n");
        return ;
    }

    for(i=s; i<M; i++)
    {
        aloow_set[d] = i;
        allow_setting(i+1, d+1);    
    }
}


void attck(int y, int x)
{
    int depth=1;
    int ny, nx;

    nx = x;
    ny = y - 1;

    while(depth<=D)
    {
        if(M<=nx || x+depth<=nx)
        {
            depth++;
            nx = x - depth+1;
            ny = y-1;
        }
        else if(ny<0 || nx<0)
        {
            nx++;
            if(nx <= x)
                ny--;
            else
                ny++;

        }
        else
        {
            if(x-depth<nx && nx<x+depth)
            {
                if(map[ny][nx] > 0)
                {
                    map[ny][nx]++;
                    return ;
                }
                nx++;
                if(nx <= x)
                    ny--;
                else
                    ny++;
            }
        }
    }
}

int main(void)
{
    
    int i, j;
    scanf("%d %d %d", &N, &M, &D);

    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            scanf("%d", &org_map[i][j]);
    
    allow_setting(0, 0);

    printf("%d\n", max);

    return 0;
}

/*
캐슬 디펜스는 성을 향해 몰려오는 적을 잡는 턴 방식의 게임이다. 게임이 진행되는 곳은 크기가 N×M인 격자판으로 나타낼 수 있다. 
격자판은 1×1 크기의 칸으로 나누어져 있고, 각 칸에 포함된 적의 수는 최대 하나이다. 격자판의 N번행의 바로 아래(N+1번 행)의 모든 칸에는 성이 있다.
성을 적에게서 지키기 위해 궁수 3명을 배치하려고 한다. 
궁수는 성이 있는 칸에 배치할 수 있고, 하나의 칸에는 최대 1명의 궁수만 있을 수 있다. 
각각의 턴마다 궁수는 적 하나를 공격할 수 있고, 모든 궁수는 동시에 공격한다. 
궁수가 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적이고, 그러한 적이 여럿일 경우에는 가장 왼쪽에 있는 적을 공격한다. 
같은 적이 여러 궁수에게 공격당할 수 있다. 공격받은 적은 게임에서 제외된다. 궁수의 공격이 끝나면, 적이 이동한다. 
적은 아래로 한 칸 이동하며, 성이 있는 칸으로 이동한 경우에는 게임에서 제외된다. 모든 적이 격자판에서 제외되면 게임이 끝난다. 
게임 설명에서 보다시피 궁수를 배치한 이후의 게임 진행은 정해져있다. 따라서, 
이 게임은 궁수의 위치가 중요하다. 격자판의 상태가 주어졌을 때, 궁수의 공격으로 제거할 수 있는 적의 최대 수를 계산해보자.
격자판의 두 위치 (r1, c1), (r2, c2)의 거리는 |r1-r2| + |c1-c2|이다.


5 5 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1

3


5 5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

15


6 5 2
1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0

14





0 0 0 0 0
0 0 3 0 0
0 3 2 3 0
3 2 1 2 3
0 0 * 0 0

(0, 0) (0, 1) (0, 2) (0, 3) (0, 4)
(1, 0) (1, 1) (1, 2) (1, 3) (1, 4)
(2, 0) (2, 1) (2, 2) (2, 3) (2, 4)
(3, 0) (3, 1) (3, 2) (3, 3) (3, 4)
(4, 0) (4, 1) (4, 2) (4, 3) (4, 4)

(4, 2)

d=1
(3, 2)
-1 0

d=2
(3, 1)
-1 -1
(2, 2)
-2 0
(3, 3)
-1 1

d=3
(3, 0)
-1 -2
(2, 1)
-2 -1
(1, 2)
-3 0
(2, 3)
-2 1
(3, 4)
-1 2

*/

