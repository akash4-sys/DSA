#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

string solve()
{
    ll n = LL, ones = 0, zero = 0;
    string s = SS, ans = "";
    s += s.back() == '1' ? "0" : "01";

    for (char &c : s)
    {
        ones += c == '1';
        zero += c == '0';
        if (c == '0')
        {
            if (ones)
                ans += to_string(ones);
            ones = 0;
        }
        else
        {
            if (zero > 1) {
                string z(zero - 1, '0');
                ans += z;
            }
            zero = 0;
        }
    }
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}