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
    string s = SS;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int d = s[i] - '0', it = i;
        for (int j = i + 1, k = 1; j < n && k <= 9; j++, k++) {
            int c = s[j] - '0';
            if (c - k > d) {
                d = c - k, it = j;
            }
        }

        if (it != i)
            for (int j = it - 1; j >= i; j--)
                swap(s[j], s[j + 1]);
        s[i] = char(d + '0');
    }
    return s;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}