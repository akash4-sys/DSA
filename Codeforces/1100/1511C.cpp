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

vec solve()
{
    int n = II, m = II;
    vec v(n), ans;
    iv(v);
    for (int i = 0; i < m; i++)
    {
        int q = II;
        int j = find(all(v), q) - v.begin() - 1;
        ans.push_back(j + 2);
        for (; j >= 0; j--)
            swap(v[j], v[j + 1]);
    }
    return ans;
}

int main()
{
    fast;
    pv(solve());
    return 0;
}