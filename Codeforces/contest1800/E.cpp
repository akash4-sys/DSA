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

string solve()
{
    int n = II, k = II, ch[26] = {0};
    string s = SS, t = SS;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(i + k + 1);
        st.insert(i + k);
        st.insert(i - k);
        st.insert(i - k - 1);
    }

    for (auto i : st)
        if (i >= 0 && i < n)
            ch[s[i] - 'a']++, ch[t[i] - 'a']--;
    
    for (int i = 0; i < 26; i++)
        if (ch[i] != 0)
            return "NO";

    for (int i = 0; i < n; i++)
        if (s[i] != t[i] && !st.count(i))
            return "NO";
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}