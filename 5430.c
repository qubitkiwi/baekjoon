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
    q->que = calloc(max, sizeof(int));
}

void q_push(queue *q, int data)
{
    int t = q->r;
    q->r = (q->r+1)%q->max;
    q->que[t] = data;
    q->num++;
}

int q_popb(queue *q)
{
    if(q->num <= 0)
        return -1;
    q->num--;
    q->r = (q->max+q->r-1)%q->max;
    return q->que[q->r];
}

int q_popf(queue *q)
{
    if(q->num <= 0)
        return -1;
    q->num--;
    int t = q->f;
    q->f = (q->f+1)%q->max;
    return q->que[t];
}

void q_del(queue *q)
{
    q->max = q->f = q->r = q->num = 0;
    free(q->que);
}

int q_size(queue *q)
{
    return q->num;
}

int make_int(char *data)
{
    int T=0, i, len = strlen(data);

    for(i=0; i<len; i++)
    {
        T *= 10;
        T += data[i]-'0';
    }
    return T;
}


int main()
{
    int T, N, i, trun, chak, t;
    char P[100001], X[4*100001+2], *ptr;
    queue q;
    q.max = 0;
    q.que = malloc(sizeof(int));

    scanf("%d", &T);

    while(T--)
    {
        scanf("%s", P);
        scanf("%d", &N);
        scanf("%s", X);

        if(q.max < N)
        {
            q_del(&q);
            q_init(&q, N);
        }
        else
        {
            q.max = N;
            q.f = q.r = q.num = 0;
        }

        ptr = strtok(X, ",][");
        while(ptr != NULL)
        {
            q_push(&q, make_int(ptr));
            ptr = strtok(NULL, ",][");
        }
        
        trun = chak = 0;
        
        for(i=0; P[i] != '\0'; i++)
        {
            if(P[i] == 'R')
            {
                trun = trun ? 0 : 1;
            }
            else if(P[i] == 'D')
            {
                if(trun == 0 && q_popf(&q) == -1)
                {
                    printf("error\n");
                    chak=1;
                    break;
                }
                else if(trun == 1 && q_popb(&q)==-1)
                {
                    printf("error\n");
                    chak=1;
                    break;
                }
            }
        }

        if(chak == 1) continue;

        if(trun == 0)
        {
            printf("[");
            while(q_size(&q)-1 >0)
            {
                printf("%d,", q_popf(&q));
            }
            t = q_popf(&q);
            if(t > 0)
                printf("%d", t);
            printf("]\n");
        }
        else
        {
            printf("[");
            while(q_size(&q)-1>0)
            {
                printf("%d,", q_popb(&q));
            }
            t = q_popf(&q);
            if(t>0)
                printf("%d", t);
            printf("]\n");
        }

    }
    return 0;
}

/* 

RDD
[1,2,3,4]
[4,3,2,1]
[3,2,1]
[2,1]


RRD
[1,1,2,3,5,8]
[1,2,3,5,8]

DD
[1,2,3,4]
[3,4]


 */