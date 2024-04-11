#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    string s;
    getline(cin, s);
    int n = II, q = II;
    vec v(n);
    iv(v);

    map<int, int> min_idx, max_idx = {{v.back(), n - 1}};
    for (int i = n - 2; i >= 0; i--) {
        min_idx[v[i]] = i;
        if (!max_idx.count(v[i]))
            max_idx[v[i]] = i;
    }
    
    while (q--)
    {
        int a = II, b = II;
        if (min_idx.count(a) && max_idx.count(b) && min_idx[a] < max_idx[b])
            pl("YES");
        else
            pl("NO");
    }
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}