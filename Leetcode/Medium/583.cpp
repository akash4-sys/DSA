#include "../../headers.h"

class Solution
{
public:
    int minDistance(string s, string r)
    {
        vector<int> dp(r.size() + 1, 0);
        for (int i = 1; i <= s.size(); i++)
        {
            int prev = 0;
            for (int j = 1; j <= r.size(); j++)
            {
                int curr = dp[j];
                dp[j] = max({dp[j], dp[j - 1], prev + (s[i - 1] == r[j - 1])});
                prev = curr;
            }
        }
        int ans = s.size() - dp[r.size()] + r.size() - dp[r.size()];
        return ans;
    }
};