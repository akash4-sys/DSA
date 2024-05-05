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

bool solve()
{
    int n = II, k = II, cnt[2] = {0};
    string s = SS;

    for (int i = 0; i < k; i++)
    {
        char c = '!';
        for (int j = i; j < n; j += k)
            if (s[j] != '?')
            {
                if (c != '!' && s[j] != c)
                    return 0;
                c = s[j];
            }
        if (c != '!')
            cnt[c - '0']++;
    }
    return max(cnt[0], cnt[1]) <= k / 2;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}