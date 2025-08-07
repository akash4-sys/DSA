#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
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

int solve()
{
    int n = II, k = II, x = -1;
    vec a(n), b(n);
    iv(a); iv(b);
    for (int i = 0; i < n; i++)
        if (b[i] != -1) {
            if (x == -1)
                x = a[i] + b[i];
            else if (x != a[i] + b[i])
                return 0;
        }
    
    for (int i = 0; i < n && x != -1; i++)
        if (b[i] == -1 && (x - a[i] > k || x < a[i]))
            return 0;

    if (x != -1)
        return 1;
    
    int mx = *max_element(all(a));
    int mn = *min_element(all(a));
    return k + mn - mx + 1;
    
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}