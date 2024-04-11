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

int solve()
{
    string s = SS;
    int ans = 0, ch[26] = {0}, cnt = 0;
    for (char &c : s)
    {
        cnt += (++ch[c - 'a'] == 1);
        if (cnt > 3) {
            ans++;
            cnt = 1;
            memset(ch, 0, sizeof(ch));
            ch[c - 'a']++;
        }
    }
    return ans + (cnt != 0);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}