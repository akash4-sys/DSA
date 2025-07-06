#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

string a, b;
int f(int i, int flag)
{
    if (i == a.size())
        return 0;

    int x = a[i] - '0', y = b[i] - '0';
    if (flag == 1)
        return 9 - x < 1 ? f(i + 1, 1) + 1 : 0;
    if (flag == 2)
        return y < 1 ? f(i + 1, 2) + 1 : 0;
    if (x == y)
        return f(i + 1, 0) + 2;
    if (y - x > 1)
        return 0;
    return min(f(i + 1, 1), f(i + 1, 2)) + 1;
}

int solve()
{
    a = SS; b = SS;
    return f(0, 0);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}