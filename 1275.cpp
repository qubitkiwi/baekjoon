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
    long long int init(int node, int s, int e);
    long long int search(int node, int s, int e, int l, int r);
    void update(int node, int s, int e, int idx, long long int diff);
    ~seg();
};

seg::seg(long long int *data, int N)
{
    data_len = N;
    this->data = data;
    seg_len = 1<< ((int)ceil(log2(N) +1));
    segment = new long long int[seg_len];
}

long long int seg::init(int node, int s, int e)
{
    if(s == e)
        return segment[node] = data[s];
    int mid = (s+e)/2;
    long long int left = init(2*node, s, mid);
    long long int right = init(2*node+1, mid+1, e);
    return segment[node] = left + right;
}

long long int seg::search(int node, int s, int e, int l, int r)
{
    if(r<s || e<l)
        return 0;
    if(l<=s && e<=r)
        return segment[node];

    int mid = (s+e)/2;
    long long int left = search(2*node, s, mid, l, r);
    long long int right = search(2*node+1, mid+1, e, l, r);
    return left + right;
}

void seg::update(int node, int s, int e, int idx, long long int diff)
{
    if(idx < s || e < idx)
        return ;
    
    segment[node] += diff;

    if(s != e)
    {
        int mid = (s+e)/2;
        update(2*node, s, mid, idx, diff);
        update(2*node+1, mid+1, e, idx, diff);
    }
}

seg::~seg()
{
    delete[] segment;
}


int main()
{
    int N, Q, x, y, a, b;
    long long int diff;
    // std::cin >> N >> Q;
    scanf("%d %d", &N, &Q);

    long long int *data = new long long int[N];
    for (int i = 0; i < N; i++)
    {
        // std::cin >> data[i];
        scanf("%lld", &data[i]);
    }
    
    seg coffee(data, N);
    coffee.init(1, 0, N-1);

    for (int i = 0; i < Q; i++)
    {
        // std::cin >> x >> y >> a >> b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if(x <= y)
        {
            // std::cout << coffee.search(1, 0, N-1, x-1, y-1) << std::endl;
            printf("%lld\n", coffee.search(1, 0, N-1, x-1, y-1));
        }
        else
        {
            // std::cout << coffee.search(1, 0, N-1, y-1, x-1) << std::endl;
            printf("%lld\n", coffee.search(1, 0, N-1, y-1, x-1));
        }

        a--;
        diff = b - data[a];
        data[a] = b;
        coffee.update(1, 0, N-1, a, diff);
    }
    delete[] data;
    return 0;
}