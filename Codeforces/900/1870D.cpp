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
#define pv(v) { for(auto &x : v) pl(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

vector<string> solve()
{
    int n = II, q = II, odd = 0;
    vec v(n);
    for (int i = 0; i < n; i++)
    {
        int a = II;
        odd += a % 2 != 0;
        v[i] = odd;
    }

    vector<string> ans;
    for (int i = 0; i < q; i++)
    {
        int l = II - 1, r = II - 1, k = II, len = r - l + 1;
        int oddLeft = odd - (v[r] - (l ? v[l - 1] : 0));
        if (k % 2)
            oddLeft += len;
        if (oddLeft % 2)
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--) {
        pv(solve());
    }
    return 0;
}