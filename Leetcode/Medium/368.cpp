#include "../../headers.h"

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &v)
    {
        if (v.size() == 1)
            return v;

        unordered_map<int, int> len, dp;
        for (int &a : v)
            len[a] = 1;

        int l = 0, x = 0;
        sort(v.begin(), v.end(), greater<int>());
        for (int a : v)
        {
            for (int i = 2, sq = sqrt(a); i <= sq && a != 1; i++)
                if (a % i == 0)
                {
                    if (a / i != i && len.count(a / i) && len[a / i] < len[a] + 1)
                        len[a / i] = len[a] + 1, dp[a / i] = a;
                    if (len.count(i) && len[i] < len[a] + 1)
                        len[i] = len[a] + 1, dp[i] = a;
                }
            if (len[a] > l)
                l = len[a], x = a;
        }
        
        vector<int> ans;
        if (v.back() == 1)
            ans.push_back(1);
        for (int i = 0; i < l; i++)
            ans.push_back(x), x = dp[x];
        return ans;
    }
};