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

void solve()
{
    int n = II, m = II, x = II - 1, i = 0;
    set<int> st[2];
    st[i].insert(x);

    while (m--)
    {
        int r = II;
        char c;
        cin >> c;
        while (!st[i].empty())
        {
            int u = *st[i].begin();
            st[i].erase(st[i].begin());
            if (c == '?' || c == '0')
                st[i ^ 1].insert((u + r) % n);
            if (c == '?' || c == '1')
                st[i ^ 1].insert((u - r + n) % n);
        }
        i ^= 1;
    }
    
    pl(st[i].size());
    for (auto u : st[i])
        pf(u + 1);
    cout << endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}