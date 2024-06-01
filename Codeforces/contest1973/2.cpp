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
    int n = II;
    vec v(n), bit(32, 0);
    iv(v);

    vv bits;
    for (int &a : v) {
        for (int i = 0; i < 32; i++)
            bit[i] += ((a >> i) & 1);
        bits.push_back(bit);
    }

    auto check = [&](int k) {
        int t = 0;
        for (int i = 0; i < 32; i++)
            if (bits[k][i])
                t |= (1 << i);
        
        for (int i = k + 1; i < n; i++)
        {
            int curr = 0;
            for (int j = 0; j < 32; j++)
                if (bits[i][j] - bits[i - k - 1][j])
                    curr |= (1 << j);
            if (curr != t)
                return 0;
        }
        return 1;
    };

    int l = 0, r = n - 1, ans = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid - 1, ans = min(ans, mid + 1);
        else
            l = mid + 1;
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