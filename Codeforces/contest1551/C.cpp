#include <bits/stdc++.h>
using namespace std;

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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, ans = 0;
    vector<string> v(n);
    iv(v);

    vv fq(n, vec(5, 0));
    for (int i = 0; i < n; i++)
        for (char &c : v[i])
            fq[i][c - 'a']++;
    
    for (int c = 0; c < 5; c++)
    {
        int sum = 0, cnt = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
            fq[i][c] -= (v[i].size() - fq[i][c]), pq.push(fq[i][c]);

        while (!pq.empty() && sum + pq.top() > 0)
            sum += pq.top(), pq.pop(), cnt++;
        ans = max(ans, cnt);
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