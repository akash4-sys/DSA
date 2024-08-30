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

vec solve()
{
    int n = II;
    vec v(n + 2), a;
    iv(v);
    sort(all(v));
    ll total = accumulate(all(v), 0LL);

    for (int i = n + 1; i >= n; i--)
    {
        ll x = total - (v[i] * 2), x_idx = -1;
        for (int j = 0; j < v.size() && x_idx == -1; j++)
            if (v[j] == x && j != i)
                x_idx = j;
        
        if (x_idx != -1)
        {
            for (int j = 0; j < v.size(); j++)
                if (j != i && j != x_idx)
                    a.push_back(v[j]);
            return a;
        }
    }
    return {-1};
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}