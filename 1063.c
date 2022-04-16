#include <stdio.h>

int move(char *T, int *king, int *point)
{
    int i, x=0, y=0;

    for(i=0; T[i] != '\0'; i++)
    {
             if(T[i] == 'R') x++;
        else if(T[i] == 'L') x--;
        else if(T[i] == 'B') y--;
        else if(T[i] == 'T') y++;
    }

    if(king[0]+x >=8 || king[1]+y >=8)
        return 0;
    if(king[0]+x <0 || king[1]+y <0)
        return 0;

    king[0] += x;
    king[1] += y;

    if(king[0]==point[0] && king[1]==point[1])
    {
        if(point[0]+x >=8 || point[1]+y >=8)
        {
            king[0] -= x;
            king[1] -= y;
            return 0;
        }
        else if(point[0]+x <0 || point[1]+y <0)
        {
            king[0] -= x;
            king[1] -= y;
            return 0;            
        }
        point[0] += x;
        point[1] += y;
    }
}


int main(void)
{
    int x_max=8, y_max=8;

    char T[3];
    int king[2], point[2];
    int N, i;

    scanf("%s", T);
    king[0] = T[0] - 'A';
    king[1] = T[1] - '1';

    scanf("%s", T);
    point[0] = T[0] - 'A';
    point[1] = T[1] - '1';

    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        scanf("%s", T);
        move(T, king, point);
    }

    printf("%c%d\n", king[0]+'A', king[1]+1);
    printf("%c%d\n", point[0]+'A', point[1]+1);

    return 0;
}