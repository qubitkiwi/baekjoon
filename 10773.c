#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int max;
    int sp;
    int *stk;
} Stack;

int initialization(Stack *s, int max)
{
    s->max = max;
    s->sp = 0;
    if((s->stk = malloc(s->max*sizeof(int))) == NULL)
    {
        return -1;
    }
    return 0;   
}


int push(Stack *s, int a)
{
    if(s->sp >= s->max)
    {
        return -1;
    }
    s->stk[s->sp++] = a;
    return 0;
}

int pop(Stack *s)
{
    if(s->sp <= 0)
    {
        return -1;
    }
    return s->stk[--s->sp];
}

int empty(Stack *s)
{
    return (s->sp <= 0);
}

void Terminate(Stack *s)
{
    if(s->stk != NULL)
    {
        free(s->stk);
    }
    s->max = s->sp = 0;
}

int main(void)
{
    int N, i, a, sum=0;
    scanf("%d", &N);

    Stack s;
    if(initialization(&s, N) ==-1)
    {
        printf("error");
    }

    for(i=0; i<N; i++)
    {
        scanf("%d", &a);
        if(a)
        {
            push(&s, a);
        }
        else
        {
            pop(&s);
        }
    }

    while(!empty(&s))
    {
        sum += pop(&s);
    }

    printf("%d\n", sum);

    Terminate(&s);

    return 0;
}