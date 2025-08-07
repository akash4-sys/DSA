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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}

vector<int> primes;

void sieve(int n = 1e5)
{
    vector<int> is(n + 1, 1);
    is[1] = 0;
    for (int p = 2; p * p <= n; p++)
        for (int i = p * p; i <= n && is[p]; i += p)
            is[i] = 0;
    
    for (int i = n; i >= 2; i--)
        if (is[i])
            primes.push_back(i);
}

void solve()
{
    int n = II;
    vector<int> ans(n + 1, 0);
    for (int &p : primes) {
        vector<int> v;
        for (int i = p; i <= n; i += p)
            if (!ans[i])
                v.push_back(i);
        for (int m = v.size(), i = 0; i < m; i++)
            ans[v[i]] = v[(i + 1) % m];
    }

    for (int i = 1; i <= n; i++)
        cout << (ans[i] ? ans[i] : i) << " ";
    cout << "\n";
}

int main()
{
    fast;
    sieve();
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}