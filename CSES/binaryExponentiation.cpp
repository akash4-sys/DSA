#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, res = 1, mod = 1e9 + 7;
        cin >> a >> b;
        for (; b; b >>= 1) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}