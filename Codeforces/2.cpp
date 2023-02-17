#ifdef __INTELLISENSE__
#include "../headers.h"
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
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

bool high(int mp[], int k)
{
    int c = 0;
    for (int i = 0; i < 51; i++)
    {
        if (mp[i] >= mp[k] && i != k)
            return 0;
        c += mp[i] == 1;
    }
    if (mp[k] == 1)
        return c == 1;
    return mp[k];
}

string solve()
{
    int n = II, k = II, mp[51] = {0};
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x = II, y = II;
        v.push_back({x, y});
        if (x <= k && k <= y)
            for (; x <= y; x++)
                mp[x]++;
    }
    if(high(mp, k))
        return "YES";
    return "NO";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}