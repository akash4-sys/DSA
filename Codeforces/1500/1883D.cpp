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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II;
    multiset<int> l, r;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        int low = II, high = II;
        if (c == '+')
            l.insert(low), r.insert(high);
        else
            l.erase(l.find(low)), r.erase(r.find(high));

        bool ans = l.upper_bound(*r.begin()) == l.end();
        !ans ? pl("YES") : pl("NO");
    }
}

int main()
{
    fast;
    solve();
    return 0;
}