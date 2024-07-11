#include "../../headers.h"

class Solution
{
public:
    int maximumLength(vector<int> &v, int k)
    {
        int ans = 0, n = v.size();
        vector dp(k, vector<int>(k, 0));
        for (int &a : v)
            for (int x = 0; x < k; x++) {
                int p = (x - (a % k) + k) % k;
                ans = max(ans, dp[a % k][x] = max(dp[a % k][x], dp[p][x] + 1));
            }
        return ans;
    }
};