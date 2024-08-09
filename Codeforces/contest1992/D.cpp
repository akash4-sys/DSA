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

bool solve()
{
    int n = II, m = II, k = II, swim = 0;
    string s = SS;
    vector<int> lands;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L')
            lands.push_back(i);
    
    lands.push_back(n);
    int i = -1, j = 0;
    while (i < n)
        if (i == -1 || s[i] == 'L') {
            if (j < lands.size() && lands[j] <= i + m)
                i = lands[j], j++;
            else
                i += m;
        }
        else if (s[i] == 'W')
            i++, swim++;
        else
            return 0;
    return swim <= k;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}