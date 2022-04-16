#include <stdio.h>

int main(void)
{
    char name[50];
    char x[] = "\?\?!";
    scanf("%s", name);
    printf("%s%s", name, x);
    
    return 0;    
}