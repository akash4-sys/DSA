#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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

class KMP
{
    void generateLPS(string &p, vector<int> &lps)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else i++;
    }

public:
    int count(string &s, string &p)
    {
        vector<int> lps(p.size(), 0);
        generateLPS(p, lps);

        int res = 0;
        for (int i = 0, j = 0; i < s.size();)
        {
            if (s[i] == p[j])
                i++, j++;
            if (j == p.size())
                res++;
            if (i < s.size() && s[i] != p[j])
                j ? j = lps[j - 1] : i++;
        }
        return res;
    }
};

int solve()
{
    int n = II, k = II, gr = II;
    string s = SS;

    int l = 1, r = ceil(n / (k * 1.0)), ans = 0;
    while (l <= r)
    {
        KMP kmp;
        int mid = (l + r) / 2;
        string p = s.substr(0, mid);
        if (kmp.count(s, p) == k)
            l = mid + 1, ans = max(ans, mid);
        else
            r = mid - 1;
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