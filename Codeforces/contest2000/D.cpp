#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    ll n = II, ans = 0;
    vec a(n + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = LL, sum[i] += sum[i - 1] + a[i];
    
    string s = "#" + SS;
    for (int i = 1, j = n; i < j; i++)
    {
        while (s[i] == 'L' && j > i && s[j] != 'R')
            j--;
        if (i < j && s[i] == 'L' && s[j] == 'R') {
            ans += (sum[j] - sum[i - 1]);
            j--;
        }
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