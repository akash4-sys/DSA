#include "../../headers.h"

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &v)
    {
        int ans = 0;
        vector<unordered_map<long long , int>> dp(v.size());
        for(int i = 1; i < v.size(); i++)
            for(int j = 0; j < i; j++)
            {
                long long d = (long long)v[i] - v[j];
                int c =  dp[j].count(d) ? dp[j][d] : 0;
                dp[i][d] += c + 1;
                ans += c;
            }
        return ans;
    }
};