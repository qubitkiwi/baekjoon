#include <stdio.h>

#define PI 3.14159265358979

int main(void)
{
    double r;
    scanf("%le", &r);

    printf("%.6f\n", PI*r*r);
    printf("%.6f\n", 2*r*r);

    return 0;
}