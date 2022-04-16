#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int max;
    int sp;
    int *stk;
}Stack;


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

int size(Stack *s)
{
    return s->sp;
}

int empty(Stack *s)
{
    return (s->sp <= 0);
}

int top(Stack *s)
{
    if(s->sp <= 0)
    {
        return -1;
    }
    return s->stk[s->sp -1];
}




int main(void)
{
    int N, i, a;
    char commind[7];

    scanf("%d", &N);

    Stack s;
    if(initialization(&s, N) ==-1)
    {
        printf("error");
    }

    for(i=0; i<N; i++)
    {
        scanf("%s", commind);
        // printf("%s\n", commind);

        if (!strcmp(commind, "push"))
        {
            scanf("%d", &a);
            push(&s, a);
        }
        else if(!strcmp(commind, "pop"))
        {
            printf("%d\n", pop(&s));
        }
        else if(!strcmp(commind, "size"))
        {
            printf("%d\n", size(&s));
        }
        else if(!strcmp(commind, "empty"))
        {
            printf("%d\n", empty(&s));
        }
        else if(!strcmp(commind, "top"))
        {
            printf("%d\n", top(&s));
        }
        
    }


    return 0;
}