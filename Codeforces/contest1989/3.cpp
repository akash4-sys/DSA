#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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

bool check(vec &a, vec &b, int x)
{
    int common = 0, bad = 0, asum = 0, n = a.size();
    for (int i = 0; i < n; i++)
        if (a[i] == -1 && b[i] == -1)
            bad++;
        else if (a[i] == 1 && b[i] == 1)
            common++;
        else if (a[i] == 1)
            asum++;

    if (asum < x) {
        int c = min(x - asum, common);
        asum += c;
        common -= c;
    }
    if (asum < x)
        return 0;
    
    int bsum = 0;
    for (int i = 0; i < n; i++)
        if (b[i] == 1 && a[i] != 1)
            bsum++;

    if (bsum < x) {
        int c = min(x - bsum, common);
        bsum += c;
        common -= c;
    }
    if (bsum < x)
        return 0;
    if (bad - common < 0)
        return 1;
    
    bad -= common;
    // extra in a
    int aex = max(asum - x, 0);
    bad -= aex;

    // extra in b
    int bex = max(bsum - x, 0);
    bad -= bex;

    if (bad <= 0)
        return 1;
    return 0;
}

int solve()
{
    int n = II, l = -n, r = n, ans = -n;
    vec a(n), b(n);
    iv(a);
    iv(b);

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(a, b, mid))
            l = mid + 1, ans = max(ans, mid);
        else
            r = mid - 1;
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