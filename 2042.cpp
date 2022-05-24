#include <iostream>
#include <cmath>

class seg
{
private:
    int data_len;
    long long int *data;
    int seg_len;
    long long int *segment;

public:
    seg(long long int *data, int N);
    long long int make_seg(int node, int start, int end);
    long long int search(int node, int start, int end, int a, int b);
    void modify(int node, int start, int end, int m, long long int data);

    ~seg();

    void print();
};

seg::seg(long long int *data, int N)
{
    this->data = data;
    data_len = N;
    seg_len = 1<< ((int)ceil(log2(N) +1));
    segment = new long long int[seg_len];
}

long long int seg::make_seg(int node, int start, int end)
{
    if(start == end)
        return segment[node] = data[start];

    int mid = (start+end)/2;
    long long int left = make_seg(2*node, start, mid);
    long long int right = make_seg(2*node+1, mid+1, end);
    segment[node] = left+right;
    return segment[node];
}

long long int seg::search(int node, int start, int end, int a, int b)
{
    if(end<a || b<start)
        return 0;
    if(a<=start && end<=b)
        return segment[node];

    int mid = (start+end)/2;
    long long int left = search(2*node, start, mid, a, b);
    long long int right = search(2*node+1, mid+1, end, a , b);
    return left+right;
}

void seg::modify(int node, int start, int end, int idx, long long int diff)
{
    if(idx < start || end < idx)
        return ;

    segment[node] += diff;

    if(start != end)
    {
        int mid = (start+end)/2;
        modify(2*node, start, mid, idx, diff);
        modify(2*node+1, mid+1, end, idx, diff);
    }
}

seg::~seg()
{
    delete[] segment;
}

void seg::print()
{
    for (int i = 0; i < seg_len; i++)
    {
        std::cout << segment[i] << " ";
    }
    std::cout << std::endl;    
}


int main()
{
    int N, M, K, a, b;
    long long int c, diff;
    // std::cin >> N >> M >> K;
    scanf("%d %d %d", &N, &M, &K);

    long long int *data = new long long int[N];
    for (int i(0); i < N; i++)
        // std::cin >> data[i];
        scanf("%lld", &data[i]);

    seg tree(data, N);
    tree.make_seg(1, 0, N-1);

    M += K;
    for (int i(0); i < M; i++)
    {
        // std::cin >> a >> b >> c;
        scanf("%d %d %lld", &a, &b, &c);
        if(a == 1)
        { 
            b--;
            diff = c - data[b];
            data[b] = c;
            tree.modify(1, 0, N-1, b, diff);
        }
        else if(a == 2)
        {
            // std::cout << tree.search(1, 0, N-1, b-1, c-1) << std::endl;
            printf("%lld\n", tree.search(1, 0, N-1, b-1, c-1));
        }
    }
        
    delete[] data;
    return 0;
}