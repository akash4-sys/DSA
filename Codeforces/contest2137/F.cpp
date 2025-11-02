#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

ll solve()
{
    int n = II;
    vec x(n), y(n);
    iv(x); iv(y);

    ll ans = 0;
    ordered_multiset st;
    for (int i = 0; i < n; i++) {
        st.insert({x[i], i});
        int k = max(x[i], y[i]);
        int cnt = st.size() - st.order_of_key({k, 0});
        auto it = st.lower_bound({k, 0});
        if (it != st.end() && it->first == k)
            cnt--;
        cnt += (x[i] == y[i]);
        ll res = 1LL * cnt * (i + 1) * (n - i);
        ans += res;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}