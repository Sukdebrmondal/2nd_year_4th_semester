#include <stdio.h>

int main()
{
    int x = 10;
    int y = 90;
    int z = 40;

    int *p, *q, *r;

    p = &x;
    q = &y;
    r = &z;

    if (*p > *q && *p > *r)
    {
        printf("the largest number is: %d", *p);
    }
    else if (*q > *p && *q > *r)
    {
        printf("the largest number is: %d", *q);
    }
    else
    {
        printf("the largest number is: %d", *r);
    }
}