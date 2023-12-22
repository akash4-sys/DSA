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
    int n = II;
    string s = '$' + SS;
    vec st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && s[st.back()] < s[i])
            st.pop_back();
        st.push_back(i);
    }

    int k = 0, m = (int)st.size() - 1;
    while (k <= m && s[st[k]] == s[st[0]])
        k++;

    int ans = m - k + 1;
    for (int i = 0; i <= m; i++)
        if (i < m - i)
            swap(s[st[i]], s[st[m - i]]);

    for (int i = 2; i <= n; i++)
        if (s[i] < s[i - 1])
            return -1;
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