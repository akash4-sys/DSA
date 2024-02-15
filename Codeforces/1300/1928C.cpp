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

void factors(unordered_set<int> &st, int pos, int n)
{
    if (n % 2)
        return;
    for (int i = 1, sq = sqrt(n); i <= sq; i++)
        if (n % i == 0)
        {
            if (n / i != i)
                if (int f = n / i, m = f / 2 + 1; f % 2 == 0 && m >= pos)
                    st.insert(m);
            if (i % 2 == 0 && i / 2 + 1 >= pos)
                st.insert(i / 2 + 1);
        }
}

int solve()
{
    int n = II, x = II;
    unordered_set<int> st;
    factors(st, x, n - x);
    factors(st, x, n + x - 2);
    return st.size();
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}