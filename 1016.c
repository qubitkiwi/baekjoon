#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int square_nono(long long int min, long long int max){
    long long int i, j, diff, increase, cut = 0;
    diff = max - min;

    char *num = (char *) calloc(diff+1, sizeof(char));
    memset(num, 1, (diff+1)*sizeof(char));

    for (i=2 ; i*i <= max; i++){
        
        increase = i*i;
        j = increase*(min/increase);

        for (; j<=max; j+=increase){
            if (j < min)
                continue;
            num[j-min] = 0;
        }
    }

    for (i=0; i <= diff; i++){
        if (num[i] > 0){
            cut++;
        }
    }

    free(num);
    return cut;
}

int main(){

    long long int min, max, cut;
    scanf("%lld %lld", &min, &max);

    cut = square_nono(min, max);
    printf("%lld\n", cut);

    return 0;
}