#include <iostream>
#include <cmath>

class seg
{
private:
    int data_len;
    int *data;
    int seg_len;
    int *segment;

public:
    seg(int *data, int N);
    int init(int node, int s, int e);
    int search(int node, int s, int e, int l, int r);
    int update(int node, int s, int e, int idx, int diff);
    void print();
    ~seg();
};

seg::seg(int *data, int N)
{
    data_len = N;
    this->data = data;
    seg_len = 1<< ((int)ceil(log2(N) +1));
    segment = new int[seg_len];
}

int seg::init(int node, int s, int e)
{
    if(s == e)
        return segment[node] = data[s];
    int mid = (s+e)/2;
    int left = init(2*node, s, mid);
    int right = init(2*node+1, mid+1, e);
    return segment[node] = (left < right) ? right : left;
}

int seg::search(int node, int s, int e, int l, int r)
{
    if(r<s || e<l)
        return 0;
    if(l<=s && e<=r)
        return segment[node];

    int mid = (s+e)/2;
    int left = search(2*node, s, mid, l, r);
    int right = search(2*node+1, mid+1, e, l, r);
    return (left < right) ? right : left;
}

int seg::update(int node, int s, int e, int idx, int V)
{    
    if(idx < s || e < idx)
        return segment[node];

    if(s == e)
        return segment[node];

    int mid = (s+e)/2;
    int left = update(2*node, s, mid, idx, V);
    int right = update(2*node+1, mid+1, e, idx, V);    
    return segment[node] = (left < right) ? right : left;
}

seg::~seg()
{
    delete[] segment;
}

void seg::print()
{
    for (int i = 0; i < seg_len; i++)
        printf("%d ", segment[i]);
    printf("\n");    
}

int main()
{
    int N, M, f(0), r;
    std::cin >> N >> M;

    int *brightness = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> brightness[i];

    seg light(brightness, N);
    light.init(1, 0, N-1);

    r = 2*(M-1);
    while(r<N)
    {
        printf("%d ", light.search(1, 0, N-1, f, r));
        f++;
        r++;
    }
    printf("\n");

    delete[] brightness;
    return 0;
}


/* 

2*(N-1) + 1

2 = 3

4 = 7
0 0 0 0 0 0 0

5 = 9
4 1 4

6 = 11
5 1 5
 */
