#include <iostream>
#include <cmath>

class Min_seg
{
private:
    int data_len;
    int *data;
    int seg_len;
    int *segment;

public:
    Min_seg(int *data, int N);
    ~Min_seg();

    int make_seg(int node, int start, int end);
    int search(int node, int start, int end, int a, int b);
};

Min_seg::Min_seg(int *data, int N)
{
    int data_len = N;
    this->data = data;
    seg_len = (1<< ((int)ceil(log2(N)) +1));
    segment = new int[seg_len];
}

Min_seg::~Min_seg()
{
    delete[] segment;
}

int Min_seg::make_seg(int node, int start, int end)
{
    if(start == end)
        return segment[node] = data[start];
    
    int mid = (start + end)/2;
    int left = make_seg(2*node, start, mid);
    int right = make_seg(2*node+1, mid+1, end);
    segment[node] = (left < right) ? left : right;
    return segment[node];
}

int Min_seg::search(int node, int start, int end, int a, int b)
{
    if(b < start || end < a)
        return __INT_MAX__;
    if(a <= start && end <= b)
        return segment[node];
    
    int mid = (start+end)/2;
    int left = search(2*node, start, mid, a, b);
    int right = search(2*node+1, mid+1, end, a, b);
    return (left < right) ? left : right;
}

class Max_seg
{
private:
    int data_len;
    int *data;
    int seg_len;
    int *segment;
public:
    Max_seg(int *data, int N);
    ~Max_seg();

    int make_seg(int node, int start, int end);
    int search(int node, int start, int end, int a, int b);
};

Max_seg::Max_seg(int *data, int N)
{
    data_len = N;
    this->data = data;
    seg_len = (1<< ((int)ceil(log2(N))+ 1));
    segment = new int[seg_len];
}

Max_seg::~Max_seg()
{
    delete[] segment;
}

int Max_seg::make_seg(int node, int start, int end)
{
    if(start == end)
        return segment[node] = data[start];
    
    int mid = (start+end)/2;
    int left = make_seg(2*node, start, mid);
    int right = make_seg(2*node+1, mid+1, end);
    segment[node] = (left < right) ? right : left;

    return segment[node];
}

int Max_seg::search(int node, int start, int end, int a, int b)
{
    if(end < a || b < start)
        return 0;
    if(a<=start && end <= b)
        return segment[node];
    
    int mid = (start+end)/2;
    int left = search(2*node, start, mid, a, b);
    int right = search(2*node+1, mid+1, end, a, b);
    return (left < right) ? right : left;
}




int main()
{
    int N, M, a, b, max, min;
    // std::cin >> N >> M;
    scanf("%d %d", &N, &M);

    int *data = new int[N];
    for (int i=0; i < N; i++)
    {
        // std::cin >> data[i];
        scanf("%d", &data[i]);
    }
    
    Max_seg max_s(data, N);
    Min_seg min_s(data, N);

    max_s.make_seg(1, 0, N-1);
    min_s.make_seg(1, 0, N-1);

    for (int i=0; i < M; i++)
    {
        // std::cin >> a >> b;
        scanf("%d %d", &a, &b);
        
        a--;
        b--;

        max = max_s.search(1, 0, N-1, a, b);
        min = min_s.search(1, 0, N-1, a, b);
        
        // std::cout << min << " " << max << std::endl;
        printf("%d %d\n", min, max);
    }    

    delete[] data;
    return 0;
}