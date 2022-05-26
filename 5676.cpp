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
    return segment[node] = left*right;
}

int seg::search(int node, int s, int e, int l, int r)
{
    if(r<s || e<l)
        return 1;
    if(l<=s && e<=r)
        return segment[node];

    int mid = (s+e)/2;
    int left = search(2*node, s, mid, l, r);
    int right = search(2*node+1, mid+1, e, l, r);
    return left*right;
}

int seg::update(int node, int s, int e, int idx, int V)
{    
    if(idx < s || e < idx)
        return segment[node];

    if(s == e)
        if(s==idx)
            return segment[node] = V;
        else
            return segment[node];

    int mid = (s+e)/2;
    int left = update(2*node, s, mid, idx, V);
    int right = update(2*node+1, mid+1, e, idx, V);    
    return segment[node] = left*right;
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
    int N, K, a, b, t, diff;
    char cmd[2];

    while(scanf("%d %d", &N, &K) != EOF)
    {
        int *data = new int[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &t);
            if(t > 0)
                t = 1;
            else if(t < 0)
                t = -1;
            
            data[i] = t;
        }
        
        seg coffee(data, N);
        coffee.init(1, 0, N-1);

        for (int i = 0; i < K; i++)
        {
            scanf("%s %d %d", cmd, &a, &b);

            if(cmd[0] == 'C')
            {
                if(b > 0)
                    b = 1;
                else if(b < 0)
                    b = -1;
                
                coffee.update(1, 0, N-1, a-1, b);
            }
            else if(cmd[0] == 'P')
            {
                t = coffee.search(1, 0, N-1, a-1, b-1);
                if(t > 0)
                    printf("+");
                else if(t < 0)
                    printf("-");
                else
                    printf("0");
            }
        }
        printf("\n");
        delete[] data;
    }
    return 0;
}