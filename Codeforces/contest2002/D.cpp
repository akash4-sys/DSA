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
#define pl(x) cout << x << "\n"
#define brk cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } brk;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

bool solve()
{
    int n = II;
    vec a(n), b(n), adist(n + 1, 0), bdist(n + 1, 0), isDelA(n + 1, 0), isDelB(n + 1, 0);
    iv(a);
    iv(b);

    for (int i = 0; i < n; i++) {
        adist[a[i]] = min(i + 1, n - i + 1);
        bdist[b[i]] = min(i + 1, n - i + 1);
    }

    int al = 0, ar = n - 1, bl = 0, br = n - 1;
    while (al < ar)
    {
        if (isDelB[a[al]] || isDelB[a[ar]]) {
            if (isDelB[a[al]])
                isDelA[a[al]] = 1, al++;
            else
                isDelA[a[ar]] = 1, ar--;
        }
        else {
            if (bdist[a[al]] >= bdist[a[ar]])
                al++;
            else
                ar--;
        }
        
        if (isDelA[b[bl]] || isDelA[b[br]]) {
            if (isDelA[b[bl]])
                isDelB[b[bl]] = 1, bl++;
            else
                isDelB[b[br]] = 1, br--;
        }
        else {
            if (adist[b[bl]] < adist[b[br]])
                bl++;
            else
                br--;
        }
    }
    return a[al] == b[bl];
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl((solve() ? "Bob" : "Alice"));
    return 0;
}