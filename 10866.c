#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __queue{
    int max;
    int f;
    int r;
    int num;
    int *que;
} queue;

void q_init(queue *q, int max)
{
    q->max = max;
    q->f = q->r = q->num = 0;
    q->que = (int*)calloc(max, sizeof(int));
}

void q_pushf(queue *q, int data)
{
    q->f = (q->max + q->f -1)%q->max;
    q->que[q->f] = data;
    q->num++;
}

void q_pushb(queue *q, int data)
{
    q->que[q->r] = data;
    q->r = (q->r+1)%q->max;
    q->num++;
}

int q_popf(queue *q)
{
    if(q->num == 0)
        return -1;

    int data = q->que[q->f];
    q->f = (q->f+1)%q->max;
    q->num--;
    return data;
}

int q_popb(queue *q)
{
    if(q->num == 0)
        return -1;
    q->num--;
    q->r = (q->max+q->r-1)%q->max;
    return q->que[q->r];
}

int q_size(queue *q)
{
    return q->num;
}

int q_empty(queue *q)
{
    return (q->num == 0);
}

int q_front(queue *q)
{
    if(q->num == 0)
        return -1;
    return q->que[q->f];
}

int q_back(queue *q)
{
    if(q->num == 0)
        return -1;
    return q->que[(q->max + q->r -1)%q->max];
}

int main()
{
    int N, data;
    char cmd[11];
    queue q;
    scanf("%d", &N);

    q_init(&q, N);

    while(N--)
    {
        scanf("%s", cmd);

        if(!strcmp(cmd, "push_front"))
        {
            scanf("%d", &data);
            q_pushf(&q, data);
        }
        else if(!strcmp(cmd, "push_back"))
        {
            scanf("%d", &data);
            q_pushb(&q, data);
        }
        else if(!strcmp(cmd, "pop_front"))
        {
            printf("%d\n", q_popf(&q));
        }
        else if(!strcmp(cmd, "pop_back"))
        {
            printf("%d\n", q_popb(&q));
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
    return 0;
}