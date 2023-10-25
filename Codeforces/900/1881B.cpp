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

int rec(vec v, int k)
{
    int c = count(all(v), v[0]);
    if (c == v.size())
        return 1;
    if (k == 0)
        return 0;
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
            if (v[i] > v[j])
            {
                vec a = v;
                a.erase(a.begin() + i);
                a.push_back(v[i] - v[j]);
                a.push_back(v[j]);
                if (rec(a, k - 1))
                    return 1;
            }
    }
    return 0;
}

string solve()
{
    int a = II, b = II, c = II;
    vec v = {a, b, c};
    int ans = rec(v, 3);
    if (ans)
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