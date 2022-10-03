#include "../../headers.h"

// Same logic as lcs just return line is different

class Solution
{
public:
    int minInsertions(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        vector<int> dp(s.size() + 1, 0);
        for (int i = 1; i <= s.size(); i++)
        {
            int prev = 0;
            for (int j = 1; j <= s.size(); j++)
            {
                int curr = dp[j];
                dp[j] = max({dp[j], dp[j - 1], prev + (s[i - 1] == r[j - 1])});
                prev = curr;
            }
        }
        return s.size() - dp[s.size()];
    }
};