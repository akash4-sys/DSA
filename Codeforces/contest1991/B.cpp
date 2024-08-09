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
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vector<int> solve()
{
    int n = II;
    vector<int> v(n - 1), ans(n, 0);
    iv(v);
    v.push_back(0);
    ans[0] = v[0];

    for (int i = 0; i < 30; i++)
        for (int j = 0; j < n - 1; j++)
        {
            bool need = v[j] & (1 << i), have = ans[j] & (1 << i);
            if (need && have)
                ans[j + 1] |= (1 << i);
            else if (!need && !have && (v[j + 1] & (1 << i)))
                ans[j + 1] |= (1 << i);
            else if (need && !have)
                return {-1};
        }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}