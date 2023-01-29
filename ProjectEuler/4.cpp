#include "../headers.h"

bool palindrome(long long n)
{
    long long r = 0, x = n;
    for (; n; n /= 10)
        r = (r * 10) + (n % 10);
    return r == x;
}

void brute()
{
    using ll = long long;
    ll ans = LLONG_MIN;
    for (ll i = 100; i <= 999; i++)
        for (ll j = 100; j <= 999; j++)
            if (palindrome(i * j))
                ans = max(ans, i * j);
    cout<<ans;
}

int main()
{
    brute();
}