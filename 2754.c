#include <stdio.h>

int main(void)
{
    double anw;
    char A[3];
    scanf("%s", A);

    if(A[0] == 'A') anw = 4;
    else if(A[0] == 'B') anw = 3;
    else if(A[0] == 'C') anw = 2;
    else if(A[0] == 'D') anw = 1;
    else if(A[0] == 'F') anw = 0;

    if(A[1] == '+') anw += 0.3;
    else if(A[1] == '-') anw -= 0.3;

    printf("%.1f\n", anw);

    return 0;
}