#include "../../headers.h"

class Solution
{
public:
    int minimumDifference(vector<int> &v)
    {
        int ans = INT_MAX, n = v.size() / 2;
        vector<vector<int>> dp(n + 1);
 
        for (int i = 0; i < (1 << n); i++)
        {
            int d = 0, k = __builtin_popcount(i);
            for (int j = 0; j < n; j++)
                d += (i & (1 << j)) ? v[j] : -v[j];
            dp[k].push_back(d);
        }

        for(auto &vec: dp)
            sort(vec.begin(), vec.end());
        
        for (int i = 0; i < (1 << n); i++)
        {
            int d = 0, k = n - __builtin_popcount(i);
            for(int j = 0; j < n; j++)
                d += (i & (1 << j)) ? v[j + n] : -v[j + n];
            auto it = lower_bound(dp[k].begin(), dp[k].end(), -d);
            if(it != dp[k].begin())
                ans = min(ans, abs(d + *prev(it)));
            if(it != dp[k].end())
                ans = min(ans, abs(d + *it));
        }
        return ans;
    }
};



// TLE
class Solution
{
public:
    int minimumDifference(vector<int> &v)
    {
        int ans = INT_MAX;
        for (int i = 1; i < (1 << v.size()) / 2; i++)
        {
            int x = 0, y = 0, a = 0, b = 0;
            for (int j = 0; j < v.size(); j++)
                if (i & (1 << j))
                    x += v[j], a++;
                else
                    y += v[j], b++;
            if(a == b)
                ans = min(ans, abs(x - y));
        }
        return ans;
    }
};

// @lc app=leetcode id=2035 lang=cpp