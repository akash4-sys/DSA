#include "../headers.h"

void factors(long long n)
{
    long long ans = LLONG_MIN;
    if (n == 2)
        ans = max(ans, n);
    for (long long i = 2, sq = sqrt(n); i <= sq; i++)
        for (; !(n % i); n /= i)
            ans = max(ans, i);
    if (n > 2)
        ans = max(ans, n);
    cout << ans << endl;
}

int main()
{
    long long n = 600851475143;
    factors(n);
}