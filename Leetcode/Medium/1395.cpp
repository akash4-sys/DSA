#include "../../headers.h"

class Solution
{
public:
    int numTeams(vector<int> &v)
    {
        int ans = 0, n = v.size();
        for (int i = 1; i < n - 1; i++)
        {
            int less[2] = {0}, grt[2] = {0};
            for(int j = 0; j < n; j++)
            {
                if(v[i] < v[j])
                    ++less[j > i];
                if(v[i] > v[j])
                    ++grt[j > i];
            }
            ans += (less[0] * grt[1]) + (grt[0] * less[1]);
        }
        return ans;
    }
};

// @lc app=leetcode id=1395 lang=cpp