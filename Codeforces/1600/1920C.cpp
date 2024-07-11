#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

vector<int> factors(int x)
{
    vector<int> f;
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0)
        {
            if (x / i != i)
                f.push_back(x / i);
            f.push_back(i);
        }
    return f;
}

int solve()
{
    int n = II, ans = 0;
    vector<int> v(n);
    iv(v);

    for (int k : factors(n))
    {
        int g = 0;
        for (int i = 0; i + k < n; i++)
            g = __gcd(g, abs(v[i] - v[i + k]));
        ans += (g != 1);
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