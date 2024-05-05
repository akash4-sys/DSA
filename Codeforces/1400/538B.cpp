#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// coin change dp with combination print

vector<int> v;

void binary(int n) {
    string s = "";
    for (; n; n >>= 1)
        s += (n & 1) ? "1" : "0";
    reverse(s.begin(), s.end());
    v.push_back(stoi(s));
}

int main()
{
    fast;
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e7), path = dp;
    dp[0] = 0;
    for (int i = 1; i <= 64; i++)
        binary(i);
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 64; j++)
            if (i >= v[j] && dp[i - v[j]] + 1 < dp[i])
                dp[i] = dp[i - v[j]] + 1, path[i] = j;

    cout << dp[n] << "\n";
    for (; n != 0; n -= v[path[n]])
        cout << v[path[n]] << " ";
    return 0;
}