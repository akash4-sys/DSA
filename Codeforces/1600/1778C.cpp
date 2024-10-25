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

ll calc(string &a, string &b) {
    ll cnt = 0, res = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b[i])
            cnt++;
        else
            res += (cnt * (cnt + 1)) / 2, cnt = 0;
    return res + (cnt * (cnt + 1)) / 2;
}

ll solve()
{
    ll n = II, k = II, m = 0, ch[26] = {0}, ans = 0;
    string a = SS, b = SS;
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (ch[a[i] - 'a'] == 0 && a[i] != b[i])
            v.push_back(a[i] - 'a'), m++, ch[a[i] - 'a']++;
    
    k = min(k, m);
    if (k == 0)
        return calc(a, b);
    
    for (int mask = 1; mask <= (1 << m); mask++)
        if (__builtin_popcount(mask) == k)
        {
            int change[26] = {0};
            for (int i = 0; i < m; i++)
                if (mask & (1 << i))
                    change[v[i]] = 1;
            
            ll cnt = 0, res = 0;
            for (int i = 0; i < n; i++)
                if (a[i] == b[i] || change[a[i] - 'a'])
                    cnt++;
                else
                    res += (cnt * (cnt + 1)) / 2, cnt = 0;
            res += (cnt * (cnt + 1)) / 2;
            ans = max(ans, res);
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