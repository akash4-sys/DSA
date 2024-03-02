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
#define iv(v) { for(auto &x : v) cin >> x; }

bool check(vec a, int h, int k)
{
    sort(a.begin(), a.begin() + k + 1);
    for (int i = k % 2; i <= k; i += 2)
    {
        if (a[i] > h)
            return 0;
        h -= a[i];
    }
    return 1;
}

int main()
{
    ll n = LL, h = LL, l = 0, r = n - 1;
    vec a(n);
    iv(a);
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(a, h, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    pl(l);
    return 0;
}