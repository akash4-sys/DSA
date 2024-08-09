#include <bits/stdc++.h>

using namespace std;

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

int calc(int n, string &a, string &b) {
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
        if (a[i] == '.' && a[i - 1] == 'x' && a[i + 1] == 'x' && b[i] == '.')
        {
            int flag = 1;
            for (int j = max(i - 1, 0); j <= min(i + 1, n - 1) && flag; j++)
                if (b[j] == 'x')
                    flag = 0;
            ans += flag;
        }
    return ans;
}

int solve()
{
    int n = II, ans = 0;
    string a = SS, b = SS;
    return calc(n, a, b) + calc(n, b, a);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}