#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(void)
{
    int x, y, w, h, dx, dy;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    dx = min(x, w-x);
    dy = min(y, h-y);

    printf("%d\n", min(dx, dy));

    return 0;
}