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

ll solve()
{
    int n = II, k = II;
    vec v(n), fq(n + 1, 0), cnt(n + 1, 0);
    iv(v);
    for (auto &a : v)
        fq[a]++;
    
    for (int i = 1; i <= n; i++)
        if (fq[i] % k != 0)
            return 0;
    
    ll ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        cnt[v[i]]++;
        while (cnt[v[i]] > (fq[v[i]] / k)) {
            cnt[v[j]]--;
            j++;
        }
        ans += (i - j + 1);
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