#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"

ll solve()
{
    ll n = II + 1, ans = 0;
    string s = "a" + SS;
    vector<int> v(n, 0);
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1] + (s[i] == '+' ? -1 : 1);
        for (int j = 1; j < i; j++)
            if (v[i] >= v[j - 1] && (v[i] - v[j - 1]) % 3 == 0)
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