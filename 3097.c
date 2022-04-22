#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* location(int **course, int N)
{
    int *goal = (int *)malloc(2*sizeof(int));
    for (int i = 0; i < 2; i++)
        goal[i] = 0;
    
    for (int i = 0; i < N; i++)
    {
        goal[0] += course[i][0];
        goal[1] += course[i][1];
    }
    return goal;    
}

double distance(int x, int y)
{
    return sqrt(pow(x, 2)+pow(y, 2));
}

double min_dist(int **course, int N, int *goal)
{
    double min = distance(goal[0]-course[0][0], goal[1]-course[0][1]);
    double t;
    for (int i = 1; i < N; i++)
    {
        t = distance(goal[0]-course[i][0], goal[1]-course[i][1]);
        if(t < min)
            min = t;
    }
    return min;
}


int main(void)
{
    int N, i;
    int **course, *goal;
    double dist;

    scanf("%d", &N);

    course = (int **)calloc(N, sizeof(int *));
    for(i=0; i<N; i++)
        course[i] = (int *)calloc(2, sizeof(int));

    for(i=0; i<N; i++)
        scanf("%d %d", &course[i][0], &course[i][1]);

    goal = location(course, N);
    dist = min_dist(course, N, goal);
    
    printf("%d %d\n", goal[0], goal[1]);
    printf("%.2f\n", dist);

    for(i=0; i<N; i++)
        free(course[i]);
    free(course);
    free(goal);
    return 0;
}