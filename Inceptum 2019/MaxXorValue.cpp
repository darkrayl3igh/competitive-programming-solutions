#include <stdio.h>
int main()
{
    long long n, i, j;
    long long max = 0;
    scanf("%lld", &n);
    unsigned long long a[n], b[n];
    for(i = 0;i < n; i++)
    {
        scanf("%lld", &a[i]);
        b[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (j != i) b[i] ^= a[j];
        }
        //printf("%lld %lld\n", b[i], max);
        if(b[i] >= max) max = b[i];
    }
    printf("%lld\n", max);
}
