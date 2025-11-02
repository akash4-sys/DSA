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

bool solve()
{
    int n = II, k = II;
    vec a(n);
    for (int i = 0; i < n; i++) {
        int x = II;
        a[i] = x - ((x / k) * k);
    }
    
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        int x = II;
        x -= ((x / k) * k);
        b[x]++;
    }
    
    for (int &x : a) {
        if (b.count(x) && b[x])
            b[x]--;
        else if (b.count(abs(x - k)) && b[abs(x - k)])
            b[abs(x - k)]--;
        else return 0;
    }
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}