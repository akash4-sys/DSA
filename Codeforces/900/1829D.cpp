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
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

// int f(int n, int m)
// {
//     if (n == m)
//         return 1;
//     if (n % 3 != 0)
//         return 0;
//     return f(n / 3, m) || f((n / 3) * 2, m);
// }

string solve()
{
    int n = II, m = II;
    if (n < m)
        return "NO";
    if (n == m)
        return "YES";

    deque<int> dq;
    dq.push_back(n);
    while (!dq.empty())
    {
        int x = dq.front();
        if (x % 3 == 0)
        {
            ll a = x / 3, b = 2LL * a;
            if (a == m || b == m)
                return "YES";
            dq.push_back(a);
            dq.push_back(b);
        }
        dq.pop_front();
    }
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