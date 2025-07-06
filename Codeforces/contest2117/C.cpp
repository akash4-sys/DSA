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

ll solve()
{
    int n = II, ans = 1;
    vec v(n);
    iv(v);

    map<int, int> fq, mp;
    for (auto &a : v)
        fq[a]++;
    
    if (fq[v[0]] == 1)
        return 1;

    mp[v[0]] = 1;
    int i = 1;
    fq[v[0]]--;
    while (1)
    {
        map<int, int> curr;
        while (!mp.empty()) {
            if (mp.count(v[i]) && --mp[v[i]] == 0)
                mp.erase(v[i]);
            curr[v[i]] = 1;
            if (--fq[v[i]] == 0)
                return ans + 1;
            i++;
        }
        mp = curr;
        ans++;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}