#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pl(x) cout << x << endl
#define br cout << endl

ll solve()
{
    int n = II, k = II, odd = 0;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int a = II, r = a % k;
        mp[r].push_back((a - r) / k);
    }

    ll ans = 0;
    for (auto &[r, v] : mp)
    {
        ll op = 0, m = v.size();
        if (m % 2 && odd)
            return -1;

        sort(v.begin(), v.end());
        for (int i = 1; i < m; i += 2)
            op += (v[i] - v[i - 1]);

        odd += m % 2;
        ll op2 = op;
        for (int i = m - 1; i >= 2 && m % 2; i -= 2) {
            op2 -= (v[i - 1] - v[i - 2]);
            op2 += (v[i] - v[i - 1]);
            op = min(op, op2);
        }
        ans += op;
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