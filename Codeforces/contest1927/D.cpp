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

vv solve()
{
    int n = II;
    vec v(n), left(n, INT_MIN), right(n, INT_MAX);
    iv(v);
    vv ans;

    for (int i = n - 2; i >= 0; i--)
        right[i] = (v[i] == v[i + 1]) ? right[i + 1] : i + 1;
    for (int i = 1; i < n; i++)
        left[i] = v[i] == v[i - 1] ? left[i - 1] : i - 1;

    int q = II;
    for (int i = 0; i < q; i++)
    {
        int l = II - 1, r = II - 1;
        if (v[l] == v[r])
        {
            if (right[l] < r)
                l = right[l];
            else if (left[r] > l)
                r = left[r];
            else {
                ans.push_back({-1, -1});
                continue;
            }
        }
        ans.push_back({l + 1, r + 1});
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pvv(solve());
    return 0;
}