#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main(void)
{
	int N, M;
    int *A, *B;
    int i, j, *chek;

    scanf("%d", &N);
    A = malloc(N*sizeof(int));

    for(i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int),     compare);

    scanf("%d", &M);

    B = malloc(M*sizeof(int));
    for(i=0; i<M; i++)
    {
        scanf("%d", &B[i]);
    }
    
    for(i=0; i<M; i++)
    {
        chek = bsearch(&B[i], A, N, sizeof(int), compare);

        if(chek != NULL)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }   
    }
    
	return 0;
}