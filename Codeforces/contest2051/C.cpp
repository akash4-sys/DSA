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

string solve()
{
    int n = II, m = II, k = II, c = n;
    vec a(m), b(k);
    iv(a); iv(b);
    if (k < n - 1)
        return string(m, '0');
    if (k == n)
        return string(m, '1');
    
    string ans = "";
    sort(all(b));
    for (int i = 0; i < k; i++)
        if (b[i] != i + 1) {
            c = i + 1;
            break;
        }
    
    for (int i = 0; i < m; i++)
        if (a[i] == c)
            ans += '1';
        else
            ans += '0';
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}