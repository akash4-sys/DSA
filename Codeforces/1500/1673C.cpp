#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int dp[40001][600], mod = 1e9 + 7;
vector<int> v;

void generate()
{
    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++) {
            int a = (i * 10 + j) * 10 + i;
            int b = ((i * 10 + j) * 10 + j) * 10 + i;
            v.emplace_back(a);
            v.emplace_back(b);

            for (int k = 0; k <= 9 && i < 5; k++) {
                int c = (((i * 10 + j) * 10 + k) * 10 + j) * 10 + i;
                v.emplace_back(c);
            }
        }
}

int rec(int n, int i)
{
    if (n == 0)
        return 1;
    if (i == v.size())
        return 0;
    if (dp[n][i] != -1)
        return dp[n][i];
    
    int res = rec(n, i + 1) % mod;
    if (n >= v[i])
        (res += rec(n - v[i], i)) %= mod;
    return dp[n][i] = res;
}

int main()
{
    fast;
    generate();
    memset(dp, -1, sizeof(dp));
    rec(40000, 0);

    for (int t = II; t; t--)
        cout << dp[II][0] << "\n";
    return 0;
}