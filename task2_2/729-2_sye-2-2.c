#include <stdio.h>

int main()
{
    double x, s=0;
    int i=1, n;
    (void)scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        (void)scanf("%lf", &x);
        s=x*x+s;
    }
    printf("%lf\n", s);
    return 0;
}

