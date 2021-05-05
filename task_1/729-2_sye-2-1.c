#include <stdio.h>

int main()
{
    double x,s=0;
    int i,n;
    (void)scanf("%d", &n);
    for (i = 1; i <= n; i++){
        (void)scanf("%lf", &x);
        s=s+x;
    }
    printf("%lf\n", s);
    return 0;
}

