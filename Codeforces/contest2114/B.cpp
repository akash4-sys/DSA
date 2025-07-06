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

bool solve()
{
    int n = II, k = II, cnt = 0, zero =  0,one = 0;
    string s = SS;
    for (int i = 0; i < n / 2; i++)
        if (s[i] == s[n - i - 1]) {
            cnt++;
            if (s[i] == '0') zero++;
            else one++;
        }
    
    int d = abs(k - cnt), rem = (n / 2) - cnt;
    if (!d)
        return 1;
    if (d % 2)
        return 0;
    if (k < cnt && min(one, zero) * 2 >= d)
        return 1;
    rem -= rem % 2;
    if (k > cnt && rem >= d)
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