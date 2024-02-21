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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec a;
void preprocess()
{
    a = vec(4e5 + 1, 0);
    for (int n = 1; n <= 4e5; n++)
        a[n] = a[n - 1] * 10 + (n * 9);
}

int solve()
{
    ll n = LL, ans = 0;
    string s = SS;
    for (int i = n - 1; i >= 0; i--)
    {
        ll d = s[i] - '0', digits = n - i;
        ll sum = (d * digits) + (a[digits - 1] * d);
        ans += sum;
    }
    return ans;
}

string solve2()
{
    ll n = LL, sum = 0, carry = 0, j = 0;
    string s = SS, ans(n + 1, '0');
    for (char &c : s)
        sum += (c - '0');
    
    for (int i = n; i >= 0; i--)
    {
        ll curr = sum + carry;
        ans[i] = char((curr % 10) + '0');
        carry = curr / 10;
        sum -= (s[i - 1] - '0');
    }

    for (; j < n && ans[j] == '0'; j++);
    return ans.substr(j);
}

int main()
{
    fast;
    // preprocess();
    int tc = II;
    while (tc--)
        pl(solve2());
    return 0;
}