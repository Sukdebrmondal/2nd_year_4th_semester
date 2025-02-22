// use DAC
#include <stdio.h>
int power(int a, int n)
{
    if (n == 1)
    {
        return a;
    }
    else
    {
        if (n % 2 == 0)
        {
            return power(a, (n / 2)) * power(a, (n / 2));
        }
        else
        {
            return a * power(a, (n / 2)) * power(a, (n / 2));
        }
    }
}
int main()
{
    int a, n;
    printf("Enter Base: ");
    scanf("%d", &a);
    printf("Enter power:");
    scanf("%d", &n);
    int res = power(a, n);
    printf("The result is:%d", res);
}