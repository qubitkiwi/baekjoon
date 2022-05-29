#include <iostream>
#include <cstdlib>

class coor
{
public:
    int x;
    int y;
};

int compare1(const void *a, const void *b)
{
    coor num1 = *(coor *)a;
    coor num2 = *(coor *)b;

    if (num1.x < num2.x)
        return -1;
    
    if (num1.x > num2.x)
        return 1;
        
    return 0;
}

int compare2(const void *a, const void *b)
{
    coor num1 = *(coor *)a;
    coor num2 = *(coor *)b;

    if(num1.x == num2.x)
    {
        if (num1.y < num2.y)
            return -1;
        
        if (num1.y > num2.y)
            return 1;
            
        return 0;
    }
    return 0;
}

int main()
{
    int N;
    // std::cin >> N;
    scanf("%d", &N);
    coor *A = new coor[N];

    for (int i = 0; i < N; i++)
        scanf("%d %d", &A[i].x, &A[i].y);
        // std::cin >> A[i].x >> A[i].y;

    qsort(A, N, sizeof(coor), compare1);
    qsort(A, N, sizeof(coor), compare2);

    for (int i = 0; i < N; i++)
        printf("%d %d\n", A[i].x, A[i].y);
        // std::cout << A[i].x << " " << A[i].y << std::endl;
    
    delete[] A;
    return 0;
}