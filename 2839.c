#include <stdio.h>

int main()
{

    int N;
    int division[] = {5, 3};
    int answer = 0;

    scanf("%d", &N);

    while (N>0)
    {
        if(N%5 == 0)
        {
            answer += N/5;
            break;
        }

        N -= 3;
        answer++;
    }
    if(N < 0 )
    {
        answer = -1;
    }


    printf("%d\n", answer);

    return 0;
}