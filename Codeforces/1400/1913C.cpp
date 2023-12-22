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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int check(vector<int> &v, int i)
{
    if (i < 0)
        return 0;
    if (v[i])
    {
        v[i]--;
        return 1;
    }
    return check(v, i - 1) & check(v, i - 1);
}

int checkSum(vector<int> v, int x)
{
    for (int i = 0; i < 30; i++)
        if (x & (1 << i))
        {
            if (!v[i] && (!check(v, i - 1) || !check(v, i - 1)))
                return 0;
            v[i]--;
        }
    return 1;
}

void solve()
{
    vector<int> v(30, 0);
    int m = II;
    while (m--)
    {
        int t = II;
        if (t == 1)
            v[II]++;
        else
        {
            int sum = II, res = checkSum(v, sum);
            res ? pl("YES") : pl("NO");
        }
    }
}

int main()
{
    fast;
    solve();
    return 0;
}