#include <iostream>
#include <vector>
#include <cmath>

class segment
{
private:
    std::vector<int> data;
    std::vector<int> seg;
    
public:
    segment(int N);
    void get_data(int N);
    int init(int node, int s, int e);
    int search(int node, int s, int e, int l, int r);
    ~segment();
};

segment::segment(int N)
{
    data.reserve(N);
    int len = 1 << ((int)ceil(log2(N) +1));
    seg.reserve(len);
}

segment::~segment()
{
    seg.clear();
    data.clear();
}

void segment::get_data(int N)
{
    for (int i = 0; i < N; i++)
        std::cin >> data[i];    
}

int segment::init(int node, int s, int e)
{
    if(s==e)
        return seg[node] = data[s];
    
    int mid = (s+e)/2;
    int left = init(2*node, s, mid);
    int right = init(2*node+1, mid+1, e);
    seg[node] = left + right;
    return seg[node];
}

int segment::search(int node, int s, int e, int l, int r)
{
    if(r < s || e < l)
        return 0;
    if(l<=s && e<=r)
        return seg[node];
    
    int mid = (s+e)/2;
    int left = search(2*node, s, mid, l, r);
    int right = search(2*node+1, mid+1, e, l, r);
    return left + right;
}

int main()
{
    int N, M, a, b;
    std::cin >> N >> M;

    segment seg(N);
    seg.get_data(N);
    seg.init(1, 0, N-1);
    
    for (int i = 0; i < M; i++)
    {
        // std::cin >> a >> b;
        // std::cout << seg.search(1, 0, N-1, a-1, b-1) << std::endl;

        scanf("%d %d", &a, &b);
        printf("%d\n", seg.search(1, 0, N-1, a-1, b-1));
    }
    
    return 0;
}