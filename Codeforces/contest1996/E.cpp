#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

ll solve()
{
    string s = SS;
    ll n = s.size(), ans = 0, mod = 1e9 + 7;
    vector<ll> pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pf[i] += pf[i - 1] + (s[i - 1] == '1' ? 1 : -1);
    
    map<int, ll> mp;
    for (int i = 0; i <= n; i++) {
        (ans += (mp[pf[i]] * (n - i + 1))) %= mod;
        (mp[pf[i]] += (i + 1)) %= mod;
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}