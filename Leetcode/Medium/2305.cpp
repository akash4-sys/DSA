#include "../../headers.h"

class Solution
{
    int ans = INT_MAX;
    void recurse(vector<int> &v, vector<int> &c, int k, int j)
    {
        if(j == v.size())
        {
            ans = min(*max_element(c.begin(), c.end()), ans);
            return;
        }
        for(int i = 0; i < k; i++)
        {
            c[i] += v[j];
            recurse(v, c, k, j + 1);
            c[i] -= v[j];
        }
    }

public:
    int distributeCookies(vector<int> &v, int k)
    {
        vector<int> c(k, 0);
        recurse(v, c, k, 0);
        return ans;
    }
};


// @lc app=leetcode id=2305 lang=cpp