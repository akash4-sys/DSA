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

const int mod = 1e9 + 7;
vv ncr;
void generate(int n = 1001) {
    for (int i = 0; i < n; i++)
    {
        ncr[i] = vector<long long>(i + 1, 1);
        for (int j = 1; j < i; j++)
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
    }
}

ll solve()
{
    int n = II, k = II, b = 1;
    vec v(n), cnt(n + 1, 0);
    iv(v);
    sort(all(v), greater<ll>());
    for (int i = 0; i < n; i++)
        cnt[v[i]]++;
    for (int i = k - 2; i >= 0 && v[i] == v[i + 1]; i--)
        b++;
    return ncr[cnt[v[k - 1]]][b] % mod;
}

int main()
{
    fast;
    ncr.resize(1001);
    generate();
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}