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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II;
    if (n % 2)
        return {-1};
    
    vec ans;
    for (int i = 1, c = 1; i <= n; i++)
    {
        ans.push_back(i);
        if (c == 2)
            swap(ans.back(), ans[ans.size() - 2]), c = 0;
        c++;
    }
    return ans;
}

int main()
{
    fast;
    pv(solve());
    return 0;
}