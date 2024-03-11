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

int solve()
{
    int n = II, k = II, ans = 0;
    vec a(n), h(n);
    iv(a);
    iv(h);
    h.push_back(h.back() + 1);

    for (int it = 1, p = 0; it <= n; it++)
        if (h[it - 1] % h[it])
        {
            for (int i = p, j = p, sum = 0; i < it; i++)
            {
                sum += a[i];
                while (sum > k)
                    sum -= a[j++];
                ans = max(ans, i - j + 1);
            }
            p = it;
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