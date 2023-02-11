#include "../../headers.h"

class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<int> dp = {0,1,1,1,1,1};
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= 5; k++)
                dp[k] += dp[k - 1];
        return dp[5];
    }
};


class Solution
{
    string v = "aeiou";
public:
    int countVowelStrings(int n, int st = 1, int len = 0)
    {
        if (len == n)
            return 1;
        int ans = 0;
        for (int i = st - 1; i < 5; i++)
            ans += countVowelStrings(n, i + 1, len + 1);
        return ans;
    }
};