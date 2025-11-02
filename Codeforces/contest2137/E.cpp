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

ll solve()
{
    int n = II, k = II;
    vec a(n);
    iv(a);
    
    vec fq(n + 1, 0);
    for (int &num : a)
        fq[num]++;
    
    int x = 0;
    for (int i = 0; i <= n; i++)
        if (fq[i] == 0) {
            x = i;
            break;
        }

    if (x == n)
        return accumulate(all(a), 0LL);
    
    for (int i = 0; i < n; i++)
        if (x < a[i] || (x > a[i] && fq[a[i]] > 1))
            a[i] = x;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}