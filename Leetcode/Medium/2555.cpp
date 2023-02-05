#include "headers.h"

class Solution
{
public:
    int maximizeWin(vector<int> &v, int k)
    {
        int ans = 0;
        vector<int> dp(v.size() + 1, 0);
        for (int i = 0, j = 0; i < v.size(); i++)
        {
            while (v[i] - v[j] > k)
                j++;
            dp[i + 1] = max(dp[i], i - j + 1);
            ans = max(ans, i - j + 1 + dp[j]);
        }
        return ans;
    }
};