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
    int a = II, b = II, zero = a, one = b;
    string s = SS;
    int n = s.size();
    zero -= count(all(s), '0');
    one -= count(all(s), '1');

    for (int i = 0, j = n - 1; i <= j; i++, j--)
        if (s[i] == '?' && s[j] != '?')
        {
            if (s[j] == '0' && zero > 0)
                s[i] = s[j], zero--;
            if (s[j] == '1' && one > 0)
                s[i] = s[j], one--;
            if (s[i] == '?')
                return "-1";
        }
        else if (s[j] == '?' && s[i] != '?')
        {
            if (s[i] == '0' && zero > 0)
                s[j] = s[i], zero--;
            if (s[i] == '1' && one > 0)
                s[j] = s[i], one--;
            if (s[j] == '?')
                return "-1";
        }

    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        if (i == j && s[i] == '?')
        {
            if (!one && !zero)
                return "-1";
            if (one)
                s[i] = '1', one--;
            else if (zero)
                s[i] = '0', zero--;
        }

        if (s[i] != s[j])
            return "-1";
        if (s[i] == '?')
        {
            if (one >= 2)
                s[i] = s[j] = '1', one -= 2;
            else if (zero >= 2)
                s[i] = s[j] = '0', zero -= 2;
            if (s[i] == '?')
                return "-1";
        }
    }

    if (count(all(s), '0') != a && count(all(s),'1') != b)
        return "-1";
    return s;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}