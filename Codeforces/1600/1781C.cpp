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

void solve()
{
    int n = II, best = 0;
    string s = SS, res = "";
    vector<vector<int>> ch(26);
    for (int i = 0; i < n; i++)
        ch[s[i] - 'a'].push_back(i);
    
    vector<int> ord(26);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){
        return ch[i].size() > ch[j].size();
    });
    
    for (int k = 1; k <= 26; k++)
        if (n % k == 0)
        {
            int cur = 0;
            for (int i = 0; i < k; i++)
                cur += min(n / k, (int)ch[ord[i]].size());
            
            if (cur > best)
            {
                best = cur;
                res = string(n, ' ');
                vector<char> ex;
                for (int c = 0; c < k; c++)
                    for (int i = ord[c], j = 0; j < n / k; j++)
                        if (j < ch[i].size())
                            res[ch[i][j]] = char(i + 'a');
                        else
                            ex.push_back(char(i + 'a'));
                
                for (char &c : res)
                    if (c == ' ') {
                        c = ex.back();
                        ex.pop_back();
                    }
            }
        }
    cout << n - best << "\n" << res << "\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}