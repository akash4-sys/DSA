#ifdef __INTELLISENSE__
#include "../headers.h"
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
#define pf(x) cout << x << "\n"
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, m = II, x;
    multiset<int> st;
    for (int i = 0; i < n; i++)
        cin >> x, st.insert(x);
    
    vec ans(m, -1);
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        auto it = st.upper_bound(x);
        if (it != st.begin())
        {
            ans[i] = *prev(it);
            st.erase(prev(it));
        }
    }
    pv(ans);
}

int main()
{
    fast;
    solve();
    return 0;
}