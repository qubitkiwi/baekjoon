#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int D (int x){
    return (2*x)%10000;
}

int S (int x){
    return (x + 9999) % 10000;
}

int L (int x){
    int T = x/1000;
    return (x*10 + T)%10000;
}

int R (int x){
    return x/10 + (x%10)*1000;
}


void DSLR(int A, int B){
    
    char *visit[10000] = {NULL, };
    memset(visit, 0, sizeof(char*)*10000);
    int queue[5001] = {0, };
    int f, r, num, max;
    f = r = num = 0; max = 5001;

    int x, nx, len;

    visit[A] = (char*) calloc(2, sizeof(char));
    visit[A][0] = '1';
    visit[A][1] = '\0';

    queue[r++] = A;
    num++;

    while (num>0){
        x = queue[f++];
        f %= max;
        num--;

        if (x == B)
            break;

        nx = D(x);
        if (visit[nx] == NULL){
            len = strlen(visit[x]);
            visit[nx] = calloc(len+2, sizeof(char));
            memcpy(visit[nx], visit[x], len);
            visit[nx][len] = 'D';
            visit[nx][len+1] = '\0';
            queue[r++] = nx;
            r %= max;
            num++;
        }
        
        nx = S(x);
        if (visit[nx] == NULL){
            len = strlen(visit[x]);
            visit[nx] = calloc(len+2, sizeof(char));
            memcpy(visit[nx], visit[x], len);
            visit[nx][len] = 'S';
            visit[nx][len+1] = '\0';
            queue[r++] = nx;
            r %= max;
            num++;
        }

        nx = L(x);
        if (visit[nx] == NULL){
            len = strlen(visit[x]);
            visit[nx] = calloc(len+2, sizeof(char));
            memcpy(visit[nx], visit[x], len);
            visit[nx][len] = 'L';
            visit[nx][len+1] = '\0';
            queue[r++] = nx;
            r %= max;
            num++;
        }
        
        nx = R(x);
        if (visit[nx] == NULL){
            len = strlen(visit[x]);
            visit[nx] = calloc(len+2, sizeof(char));
            memcpy(visit[nx], visit[x], len);
            visit[nx][len] = 'R';
            visit[nx][len+1] = '\0';
            queue[r++] = nx;
            r %= max;
            num++;
        }
    }

    printf("%s\n", &visit[x][1]);

    for (int i = 0; i < 10000; i++)
        free(visit[i]);
    return ;
}

int main(){

    int TC, A, B, T, idx;
    char C[5001];
    unsigned long long int anw;
    scanf("%d", &TC);

    while(TC--){
        scanf("%d %d", &A, &B);
        DSLR(A, B);
    }

    return 0;
}