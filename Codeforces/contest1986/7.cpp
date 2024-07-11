#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll solve()
{
    ll n = II, ans = 0;
    vector<int> a(n), b(n), cnt(n + 1, 0);
    vector<vector<int>> apos(n + 1), bpos(n + 1), factors(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x = II, g = __gcd(x, i + 1);
        a[i] = x / g;
        b[i] = (i + 1) / g;
        ans -= b[i] == 1;
        apos[a[i]].push_back(i);
        bpos[b[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            factors[j].push_back(i);

    auto counter = [&](int bi, int x) {
        for (int aj = bi; aj <= n; aj += bi)
            for (int i : apos[aj])
                cnt[b[i]] += x;
    };

    for (int bi = 1; bi <= n; bi++)
    {
        counter(bi, 1);
        for (int i : bpos[bi])
            for (int x : factors[a[i]])
                ans += cnt[x];
        counter(bi, -1);
    }
    return ans / 2;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}