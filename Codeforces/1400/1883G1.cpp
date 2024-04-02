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

bool check(vec &a, vec &b, int k)
{
    for (int i = k; i < a.size(); i++)
        if (a[i - k] >= b[i])
            return 0;
    return 1;
}

int solve()
{
    int n = II, m = II, l = 0, r = n;
    vec a(n - 1), b(n);
    iv(a);
    iv(b);
    a.push_back(1);
    sort(all(a));
    sort(all(b));

    while (l <= r)
    {
        int mid = (l + r) / 2;
        check(a, b, mid) ? r = mid - 1 : l = mid + 1;
    }
    return l;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}