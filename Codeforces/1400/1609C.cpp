#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

vector<int> prime;
void sieve(int n = 1e6)
{
    prime = vector<int>(n + 1, 1);
    prime[1] = 0;
    for (int p = 2; p * p <= n; p++)
        for (int i = p * p; i <= n && prime[p]; i += p)
            prime[i] = 0;
}


ll solve()
{
    int n = II, e = II;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = II;

    ll ans = 0;  
    for (int i = 0; i < n; i++)
        if (prime[v[i]])
        {
            ll l = 1, r = 1;
            for (int j = i - e; j >= 0 && v[j] == 1; j -= e, l++);
            for (int j = i + e; j < n && v[j] == 1; j += e, r++);
            ans += (l * r) - 1;
        }
    return ans;
}

int main()
{
    fast;
    sieve();
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}