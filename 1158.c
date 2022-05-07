#include <stdio.h>
#include <stdlib.h>

struct queue{
    int max;
    int f, r, num;
    int *que;
};

void q_init(struct queue *q, int max)
{
    q->max = max;
    q->f=q->r=q->num=0;
    q->que = (int*)calloc(max, sizeof(int));
}

void q_push(struct queue *q, int data)
{
    q->que[q->r] = data;
    q->r = (q->r+1)%q->max;
    q->num++;
}

int q_pop(struct queue *q)
{
    int t = q->que[q->f]; 
    q->f = (q->f+1)%q->max;
    q->num--;
    return t;
}

void q_dele(struct queue *q)
{
    q->max = q->f = q->r = q->num = 0;
    free(q->que);
}

int q_num(struct queue *q)
{
    return q->num;
}

int main()
{
    int N, K, i, *arr;
    struct queue q;
    scanf("%d %d", &N, &K);
    q_init(&q, N);

    for (i = 1; i <= N; i++)
        q_push(&q, i);

    printf("<");

    while(q_num(&q)>1)
    {
        for(i=1; i<K; i++)
            q_push(&q, q_pop(&q));
        printf("%d, ", q_pop(&q));
    }
    printf("%d>\n", q_pop(&q));

    q_dele(&q);
    return 0;
}