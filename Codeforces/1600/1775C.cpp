#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve()
{
    ll n, x, i = 63;
    cin >> n >> x;
    ll m = n;
    if (n == x)
        return n;

    for (; i >= 0; i--)
        if ((n & (1LL << i)) != (x & (1LL << i)))
            break;
    
    for (int j = i; j >= 0; j--)
        if (m & (1LL << j))
            m ^= (1LL << j);
    
    for (i++; i < 64; i++)
    {
        bool org = m & (1LL << i);
        m ^= (1LL << i);
        bool now = m & (1LL << i);
        if (!org && now)
            break;
    }
    return (n & m) == x ? m : -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}