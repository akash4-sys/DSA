#include "../../headers.h"

class Solution
{
public:
    int countDifferentSubsequenceGCDs(vector<int> &v)
    {
        int mp[200001] = {0}, ans = 0, m = INT_MIN;
        for (int i = 0; i < v.size(); i++)
            m = max(m, v[i]), mp[v[i]] = 1;
        
        for (int i = 1; i <= m; i++)
            for (int j = i, g = 0; j <= m; j += i)
            {
                if (mp[j] == 1)
                    g = gcd(g, j);
                if (g == i)
                {
                    ans++;
                    break;
                }
            }
        return ans;
    }
};


// @lc app=leetcode id=1819 lang=cpp