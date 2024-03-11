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

void solve()
{
    int n = II, mex = 0, c = 0, k = 0;
    vector<int> a(n), left(n + 1, 0), right(n, 0);
    for (int i = 0; i < n; i++)
        a[i] = II, left[a[i]]++;

    for (; mex <= n && left[mex]; mex++)
        if (left[mex] == 1) {
            pl(-1);
            return;
        }

    for (k = 0; k < n; k++)
    {
        c += (++right[a[k]] == 1 && a[k] < mex);
        left[a[k]]--;
        if (c == mex)
            break;
    }

    for (int i = 0; i < mex; i++)
        if (left[i] < 1) {
            pl(-1);
            return;
        }
    
    pl(2);
    cout << 1 << " " << k + 1 << endl;
    cout << k + 2 << " " << n << endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}