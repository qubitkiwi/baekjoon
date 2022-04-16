#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int A[3], B[3], tc, i, j, anw, c, dx, dy, dr;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d %d", &A[0], &A[1], &A[2]);
        scanf("%d %d %d", &B[0], &B[1], &B[2]);
        
        dx = abs(A[0]-B[0]); 
        dy = abs(A[1]-B[1]); 
        dr = abs(A[2]+B[2]);

        c = dx*dx + dy*dy;

        printf("%d %d %d\n", dx, dy, dr);
        printf("%d %d\n", c, dr*dr);

        if(A[0]==B[0] && A[1]==B[1] && A[2]==B[2])
            printf("-1\n");
        else if(c < dr*dr)
            printf("2\n");
        else if(c == dr*dr)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}