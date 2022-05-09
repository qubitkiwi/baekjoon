#include <stdio.h>

char sol(int N)
{
    char moo[] = "moo";
    int len = 3;
    int k = 3;

    while(1)
    {
        if(N<=3)
            return moo[N-1];

        if(N<=2*len+k+1)
        {
            if(len<N && N<=len+k+1)
            {
                if(N-len==1)
                    return 'm';
                else
                    return 'o';
            }
            else
            {
                N = N-(len+k+1);
                len = 3;
                k = 3;
            }
        }
        else
        {
            len = 2*len+k+1;
            k++;
        }
    }    
}

int main()
{
    int N;
    char moo;
    scanf("%d", &N);

    moo = sol(N);
    printf("%c\n", moo);

    return 0;
}

/*
S(k)는 S(k-1)과 o가 k+2개인 수열 "m o ... o" 와 
       S(k-1)을 합쳐서 만들 수 있다.

moo mooo moo moooo moo mooo moo mooooo 

S(0) = moo
S(1) = moo mooo moo
S(2) = moo mooo moo / moooo / moo mooo moo
s(3) = moo mooo moo moooo moo mooo moo / mooooo / moo mooo moo moooo moo mooo moo
       123 4567 89  11    16  19   23    26       32

3
3 4 3


s(0) = 3;
s(1) = 2*s(0) + 4+1
s(2) = 2*s(1) + 5+1

s(k-3) = 2*s(k) + k+1



*/
