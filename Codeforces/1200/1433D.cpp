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
    int n = II, k = 0;
    vec v(n);
    iv(v);
    set<int> st;
    for (int a : v)
        st.insert(a);
    
    if (st.size() == 1) {
        pl("NO");
        return;
    }

    pl("YES");
    for (int i = 1; i < n; i++)
        if (v[0] != v[i]) {
            pf(1) << i + 1 << endl;
            k = i;
        }
    
    for (int i = 1; i < n; i++)
        if (v[i] == v[0])
            pf(k + 1) << i + 1 << endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}