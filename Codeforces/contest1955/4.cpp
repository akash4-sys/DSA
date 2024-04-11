#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, m = II, k = II, ans = 0, cnt = 0;
    vec a(n), b(m);
    iv(a);
    iv(b);

    map<int, int> mpb, mpa;
    for (int x : b)
        mpb[x]++;
    
    for (int i = 0; i < m; i++)
        cnt += (mpb[a[i]] >= ++mpa[a[i]]);

    ans = cnt >= k;
    for (int i = 1; i <= n - m; i++)
    {
        cnt -= mpa[a[i - 1]] <= mpb[a[i - 1]];
        mpa[a[i - 1]]--;
        cnt += mpb[a[i + m - 1]] >= ++mpa[a[i + m - 1]];
        ans += cnt >= k;
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}