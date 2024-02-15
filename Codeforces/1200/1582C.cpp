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

int count(string &s, char x, int l, int r)
{
    int res = 0;
    while (l <= r)
        if (s[l] != s[r])
        {
            if (x == '0')
                return res + min(count(s, s[l], l + 1, r), count(s, s[r], l, r - 1)) + 1;
            if (x != s[l] && x != s[r])
                return s.size() + 1;
            l += s[l] == x;
            r -= s[r] == x;
            res++;
        }
        else l++, r--;
    return res;
}

int solve()
{
    int n = II;
    string s = SS;
    int ans = count(s, '0', 0, n - 1);
    return ans >= n ? -1 : ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}