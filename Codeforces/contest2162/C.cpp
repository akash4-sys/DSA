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

vec solve()
{
    int a = II, b = II, x = a ^ b;
    if (a == b)
        return {0};
    
    vec ans;
    for (int i = 0; i < 32; i++) {
        int p = 1 << i;
        if (x & p) {
            if (p > a) return {-1};
            ans.push_back(p);
            a ^= p;
        }
    }
    pl(ans.size());
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--) {
        pv(solve());
    }
    return 0;
}