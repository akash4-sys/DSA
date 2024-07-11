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
#define st set<string>

void f(vec &ans, st &st1, st &st2, st &st3, int i) {
    for (auto &s : st1)
        if (!st2.count(s) && !st3.count(s))
            ans[i] += 3;
        else if (st2.count(s) && !st3.count(s))
            ans[i] += 1;
        else if (!st2.count(s) && st3.count(s))
            ans[i] += 1;
}

vec solve()
{
    int n = II;
    set<string> st1, st2, st3;
    for (int i = 0; i < n; i++)
        st1.insert(SS);
    for (int i = 0; i < n; i++)
        st2.insert(SS);
    for (int i = 0; i < n; i++)
        st3.insert(SS);

    vec ans(3, 0);
    f(ans, st1, st2, st3, 0);
    f(ans, st2, st1, st3, 1);
    f(ans, st3, st2, st1, 2);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}