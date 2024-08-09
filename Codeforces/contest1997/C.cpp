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

ll solve()
{
    int n = II;
    ll ans = 0;
    string s = SS;
    stack<int> st;
    for (int i = 0, open = 0; i < n; i++)
        if (s[i] == '(')
            open++, st.push(i);
        else if (s[i] == ')')
            ans += (i - st.top()), open--, st.pop();
        else if (s[i] == '_')
        {
            if (open > 0)
                ans += (i - st.top()), s[i] = ')', open--, st.pop();
            else
                s[i] = '(', open++, st.push(i);
        }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}