#include <stdio.h>

int main()
{
    const int *a;
    const int b = 10;
    int c = 20;
    char d = 'a';

    a = &b;
    printf("%p\n", a);
    a = &c;
    printf("%d\n", *a);
    c = 30;
    printf("%d\n", *a);
    a = &d;
    printf("%d\n", *a);
    return (0);
}