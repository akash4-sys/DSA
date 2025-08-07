#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long mod)
{
    long long res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

int main()
{
    int t, mod = 1e9 + 7;
    cin >> t;
    while (t--)
    {
        long long a, b, c, res = 1;
        cin >> a >> b >> c;
        for (; c; c >>= 1) {
            if (c & 1) {
                res = (res * power(a, b, mod)) % mod;
            }
            b = (b * b) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}