#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if(q->num < 1)
        return -1;

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

int q_size(struct queue *q)
{
    return q->num;
}

int q_empty(struct queue *q)
{
    return !(q->num>0);
}

int q_front(struct queue *q)
{
    if(q->num>0)
        return q->que[q->f];
    return -1;
}

int q_back(struct queue *q)
{
    if(q->num>0)
        return q->que[q->r-1];
    return -1;
}

int main()
{
    int N, t;
    char cmd[6];
    struct queue q;
    scanf("%d", &N);

    q_init(&q, N);

    while(N--)
    {
        scanf("%s", cmd);

        if(!strcmp(cmd, "push"))
        {
            scanf("%d", &t);
            q_push(&q, t);
        }
        else if(!strcmp(cmd, "pop"))
        {
            printf("%d\n", q_pop(&q));
        }
        else if(!strcmp(cmd, "size"))
        {
            printf("%d\n", q_size(&q));
        }
        else if(!strcmp(cmd, "empty"))
        {
            printf("%d\n", q_empty(&q));
        }
        else if(!strcmp(cmd, "front"))
        {
            printf("%d\n", q_front(&q));
        }
        else if(!strcmp(cmd, "back"))
        {
            printf("%d\n", q_back(&q));
        }
    }

    q_dele(&q);
    return 0;
}