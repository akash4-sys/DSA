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
#define pf(x) cout << x <<
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

// ! can't understand how ans is 25 for s = 22

ll cnt[13] = {0};
void preProcess()
{
    cnt[1] = 1;
    ll base = 10;
    for (int digits = 2; digits <= 12; digits++)
    {
        ll curr = (cnt[digits - 1] * 8) + base;
        cnt[digits] += cnt[digits - 1] + curr;
        base *= 10;
    }
}

ll solve()
{
    string s = SS;
    ll n = 0, digits = s.size();
    ll base = stoll("1" + string(digits - 1, '0'));

    for (int i = 0; i < s.size(); i++, digits--)
    {
        char c = s[i];
        ll nums = 0;
        if (digits > 1)
            nums += 1LL * cnt[digits - 1] * (c - '0');

        if (c == '4')
            nums += (digits == 1 ? 1 : stoll(s.substr(i, s.size())));
        else if (c > '4')
            nums += base;

        n += nums;
        base /= 10;
    }
    return n + stoll(s);
}

void solve2()
{
    ll k = LL;
    vector<int> digits;
    for (; k; k /= 9)
        digits.push_back(k % 9);
    
    reverse(all(digits));
    for (int i = 0; i < digits.size(); i++)
        cout << (digits[i] < 4 ? digits[i] : digits[i] + 1);
    br;
}

int main()
{
    fast;
    // preProcess();
    int tc = II;
    while (tc--)
    {
        // pl(solve());
        solve2();
    }
    return 0;
}