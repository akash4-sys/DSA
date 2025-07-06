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
#define pyn(x) cout << (x ? "Yes" : "No") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

bool solve()
{
    int n= II;
    string s = SS;
    int l[26] = {0},  r[26]  = {0};
    l[s[0] - 'a']++;
    for (int i = 1; i < n - 1; i++) {
        if (l[s[i] - 'a'])
            return 1;
        l[s[i] - 'a']++;
    }

    r[s.back() - 'a']++;
    for (int i = n - 2; i > 0; i--) {
        if (r[s[i] - 'a'])
            return 1;
        r[s[i] - 'a']++;
    }
    return 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}