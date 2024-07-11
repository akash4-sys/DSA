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

vec solve()
{
    int n = II;
    string s = SS;
    vec v(n, 0), ans(n, 0);
    for (int i = 0; i <= n / 2; i++)
        v[i] = n - i - 1;
    for (int i = (n / 2) + 1; i < n; i++)
        v[i] = i;
    if (n % 2 == 0)
        v[n / 2] = n / 2;
    
    ll sum = 0;
    vec diff(n, 0);
    for (int i = 0; i < n; i++) {
        int d = (s[i] == 'L' ? i : n - i - 1);
        if (d < v[i])
            diff[i] = v[i] - d;
        sum += d;
    }
    sort(all(diff), greater<ll>());

    for (int i = 0; i < n; i++) {
        sum += diff[i];
        ans[i] = sum;
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}