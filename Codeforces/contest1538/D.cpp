#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int countP(int n)
{
    int cnt = 0;
    if (n == 2)
        cnt++;
    for (int i = 2, sq = sqrt(n); i <= sq; i++)
        for (; !(n % i); n /= i)
            cnt++;
    if (n > 2)
        cnt++;
    return cnt;
}

int solve()
{
    int a = II, b = II, k = II, g = __gcd(a, b);
    if (k == 1)
        return a == b ? 0 : (a == g || b == g);
    
    int x = countP(a / g) + countP(b / g);
    if (x >= k)
        return 1;
    
    int m = countP(g);
    for (int f = 1; f <= m; f++)
        if (k <= (f * 2) + x)
            return 1;
    return 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}