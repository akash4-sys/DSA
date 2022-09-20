#include "../../headers.h"

// Can be done using Rabin karp algorithm

// Time complexity O(N^2)
// Space Complexity - O(N^2)

class Solution
{
public:
    int findLength(vector<int> &a, vector<int> &b)
    {
        int ans = 0;
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        for (int i = a.size() - 1; i >= 0; i--)
            for (int j = b.size() - 1; j >= 0; j--)
                if (a[i] == b[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1, ans = max(ans, dp[i][j]);
        return ans;
    }
};