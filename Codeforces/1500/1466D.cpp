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
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}

void solve()
{
    ll n = II, sum = 0;
    vector<vector<ll>> v(n, vector<ll>(2, 0));
    for (int i = 0; i < n; i++)
        v[i][0] = LL, sum += v[i][0];

    for (int i = 1; i < n; i++)
        v[II - 1][1]++, v[II - 1][1]++;
    
    sort(v.rbegin(), v.rend());
    cout << sum << " ";
    for (int k = 2, i = 0; k < n; k++)
    {
        while (i < n && v[i][1] == 1)
            i++;
        if (i != n)
            sum += v[i][0], v[i][1]--;
        cout << sum << " ";
    }
    cout << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}