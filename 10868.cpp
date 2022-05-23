#include <iostream>
#include <cmath>

class Min_segment
{
private:
    int data_len;
    int *data;

    int seg_len;
    int *segment;

public:
    Min_segment(int *arr, int N);
    ~Min_segment();

    int make_seg(int node, int start, int end);
    int search(int node, int start, int end, int a, int b);
};

Min_segment::Min_segment(int *arr, int N)
{
    data_len = N;
    seg_len = 1 << ((int)ceil(log2(data_len))+1);

    data = arr;
    segment = new int[seg_len];
}

Min_segment::~Min_segment()
{
    delete[] data;
    delete[] segment;
}

int Min_segment::make_seg(int node, int start, int end)
{
    if(start == end)
        return segment[node] = data[start];

    int mid = (start + end)/2;
    int left = make_seg(2*node, start, mid);
    int right = make_seg(2*node+1 ,mid+1, end);
    segment[node] = (left < right)?  left : right;

    return segment[node];
}

int Min_segment::search(int node, int start, int end, int a, int b)
{
    if(b < start || end < a)
        return  __INT_MAX__;
    if(a <= start && end <= b)
        return segment[node];

    int mid = (start + end)/2;
    int left = search(2*node, start, mid, a, b);
    int right = search(2*node+1, mid+1, end, a, b);
    return (left < right) ? left : right;
}

int main()
{
    int N, M, a, b, t;
    std::cin >> N >> M;

    int* arr = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    
     Min_segment min(arr, N); //얕은 복사
     min.make_seg(1, 0, N-1);

     for (int i = 0; i < M; i++)
     {
        //std::cin >> a >> b;
        scanf("%d %d", &a, &b);
        t = min.search(1, 0, N - 1, a - 1, b - 1);
        //std::cout << t << std::endl;
        printf("%d\n", t);

     } 

    return 0;
}