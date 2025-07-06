#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
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

void test(int n, vv &ans) {
    vv v(n, vec(n));
    for (auto &r : v)
        iota(all(r), 1);
    for (auto t : ans)
        reverse(v[t[0] - 1].begin() + t[1] - 1, v[t[0] - 1].begin() + t[2]);
    pvv(v);
}

vv solve()
{
    int n = II;
    vv ans;
    ans.push_back({1, 1, n});
    for (int i = 1; i < n; i++) {
        ans.push_back({i + 1, 1, i});
        ans.push_back({i + 1, i + 1, n});
    }
    pl(ans.size());
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pvv(solve());
    return 0;
}