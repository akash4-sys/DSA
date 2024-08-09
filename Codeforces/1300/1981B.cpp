#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

ll solve()
{
    ll n = II, m = II, ans = 0;
    for (int i = 0; i <= 30; i++)
        if (n & (1 << i))
            ans |= (1 << i);
        else
        {
            ll x = n % (1LL << (i + 1)), p = 1 << i, moves = m + 1;
            if (n >= p)
                moves = x + 1;
            moves = min(moves, p - x);
            if (moves <= m)
                ans |= p;
        }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}