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
    ll n = II, a = 0, b = 0, x = 0;
    vec even, odd;
    for (int i = 0; i < n; i++) {
        int a = II;
        if (a % 2)
            odd.push_back(a);
        else
            even.push_back(a);
    }
    sort(all(even));
    sort(all(odd));

    while (even.size() || odd.size())
    {
        if (x)
        {
            ll p = odd.size() ? odd.back() : 0;
            ll q = even.size() ? even.back() : 0;
            if (p > q)
                b += p, odd.pop_back();
            else if (p < q)
                even.pop_back();
        }
        else
        {
            ll p = even.size() ? even.back() : 0;
            ll q = odd.size() ? odd.back() : 0;
            if (p > q)
                a += p, even.pop_back();
            else if (p < q)
                odd.pop_back();
        }
        x ^= 1;
    }
    
    if (a == b)
        return "Tie";
    return a < b ? "Bob" : "Alice";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}