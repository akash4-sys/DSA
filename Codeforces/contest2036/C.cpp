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

string r = "1100";

void solve()
{
    string s = SS;
    int n = s.size(), q = II;
    set<int> st;
    for (int i = 0; i < n - 3; i++) {
        int f = 1;
        for (int j = i, k = 0; k < 4; j++, k++)
            if (s[j] != r[k])
                f = 0;
        if (f)
            st.insert(i);
    }

    while (q--)
    {
        int idx = II - 1, v = II;
        s[idx] = char(v + '0');
        for (int i = max(idx - 3, 0); i <= idx; i++)
            if (i + 3 < n)
            {
                int f = 1;
                for (int j = i, k = 0; k < 4; j++, k++)
                    if (s[j] != r[k])
                        f = 0;
                if (!f && st.find(i) != st.end())
                    st.erase(i);
                if (f)
                    st.insert(i);
            }
        if (!st.empty())
            pyn(1);
        else
            pyn(0);
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}