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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    string s = SS;
    int one = 0, zero = 0;
    for (char &c : s)
        one += c == '1', zero += c == '0';
    
    if (one == zero)
        return 0;

    reverse(all(s));
    int pre_one = one, pre_zero = zero;
    for (int i = 0; i < s.size(); i++)
    {
        pre_one -= s[i] == '1';
        pre_zero -= s[i] == '0';
        if (zero >= pre_one && one >= pre_zero)
            return i + 1;
    }
    return s.size();
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}