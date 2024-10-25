#include <bits/stdc++.h>
using namespace std;

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

int solve()
{
    int n = II;
    vec v(n);
    iv(v);
    auto f = [&](int st){
        int x = 0, cnt = 0;
        for (int i = st; i < n; i += 2)
            x = max(x, v[i]), cnt++;
        return x + cnt;
    };

    return max(f(1), f(0));
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}