#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str_add(const char *A, const char *B){

    int A_len = strlen(A);
    int B_len = strlen(B);
    int diff_len = B_len - A_len;
    char *result = (char*) calloc(B_len+1, sizeof(char));
    memcpy(result, B, (B_len + 1)*sizeof(char));

        
    for (int i = A_len-1; i >= 0; i--){
        result[i+diff_len] += A[i] - '0';
    }

    for (int i = B_len-1; i > 0; i--){
        if (result[i] > '9'){
            result[i] -= 10;
            result[i-1] += 1;
        }
    }

    if(result[0] > '9'){
        char *result2 = (char*) calloc(B_len+2, sizeof(char));
        memcpy(&result2[1], result, (B_len + 1)*sizeof(char));        
        free(result);
        result2[0] = '1';
        result2[1] -= 10;        
        return result2;
    }

    return result;
}

int main(){
    int N;
    char *A, *B, *C;

    scanf("%d", &N);

    A = (char*) calloc(2, sizeof(char));
    B = (char*) calloc(2, sizeof(char));

    A[0] = '0';
    A[1] = '\0';

    B[0] = '1';
    B[1] = '\0';

    if (N == 1){
        printf("%s\n", B);
        return 0;
    }

    if (N == 0){
        printf("%s\n", A);
        return 0;
    }

    for (int i = 2; i <= N; i++){
        C = str_add(A, B);
        
        free(A);
        A = B;
        B = C;
    }
    

    printf("%s\n", C);

    free(A);
    free(B);
    // free(C);

    return 0;
}


/* 

0 + 1 = 1
1 + 1 = 2
1 + 2 = 3
2 + 3 = 5




 */