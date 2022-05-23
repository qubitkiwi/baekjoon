#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int make_seg(int *segment, int *data, int node, int start, int end)
{
    if(start == end)
        return segment[node] = data[start];
    
    int mid = (start + end)/2;
    int left = make_seg(segment, data, 2*node, start, mid);
    int right = make_seg(segment, data, 2*node+1 ,mid+1, end);
    segment[node] = (left < right) ? left : right;

    return segment[node];
}

int search(int *segment, int node, int start, int end, int a, int b)
{
    if(b < start || end < a)
        return __INT_MAX__;
    if(a <= start && end <= b)
        return segment[node];
    
    int mid = (start + end)/2;
    int left = search(segment, 2*node, start, mid, a, b);
    int right = search(segment, 2*node+1, mid+1, end, a, b);
    return (left < right) ? left : right;
}

int main()
{
    int N, M, seg_len, i, a, b;
    int *data, *segment;
    scanf("%d %d", &N, &M);

    data = calloc(N, sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &data[i]);
    
    seg_len = 1 << ((int)log2(N) +2);
    segment = calloc(seg_len, sizeof(int));

    make_seg(segment, data, 1, 0, N-1);

    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", search(segment, 1, 0, N-1, a-1, b-1));
    }

    free(data);
    free(segment);

    return 0;
}