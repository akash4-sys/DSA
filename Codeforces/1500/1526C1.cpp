#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


// ll rec(vector<int> &v, int i, int k) {
//     if (i > v.size())
//         return 0;
//     if (dp[i][k] != -1)
//         return dp[i][k];
    
//     if (k && dp[i - 1][k - 1] + v[i] >= 0)
//         return max(rec(v, i + 1, k + 1) + v[i], rec(v, i + 1, k));
//     return rec(v, i + 1, )
// }

int main()
{
    fast;
    int n;
    cin >> n;
    vector<ll> v(n), dp(n + 1, -1);
    for (ll &a : v)
        cin >> a;
    
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int k = i + 1; k > 0; k--)
            if (dp[k - 1] > -1)
                dp[k] = max(dp[k], dp[k - 1] + v[i]);
    
    for (int k = n; k >= 0; k--)
        if (dp[k] > -1) {
            cout << k;
            return 0;
        }
    cout << 0;
    return 0;
}