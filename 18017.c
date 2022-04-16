#include <stdio.h>
#define c 299792458.0

int main(void)
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.2lf\n", (a + b) / (1 + (a * b) / (c * c)));

    return 0;
}