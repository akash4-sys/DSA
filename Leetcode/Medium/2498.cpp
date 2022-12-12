#include "../../headers.h"
#define vec vector<int>

class Solution
{
public:
    int maxJump(vector<int> &v)
    {
        int n = v.size(), ans = v[1] - v[0];
        for(int i = 2; i < n; i++)
            ans = max(ans, v[i] - v[i - 2]);
        return ans;
    }
}; 


// Intutive to me
class Solution
{
public:
    int maxJump(vector<int> &v)
    {
        int n = v.size(), ans = INT_MIN, l = 0, prev = -1;
        vec vis(n, 0);
        for(int i = 2; i < n; i+=2)
            l = i, ans = max(ans, v[i] - v[i - 2]), vis[i] = 1;

        if(l != n - 1)
            ans = max(ans, v.back() - v[l]);
        
        vis[n - 1] = 0;
        for(int i = n - 1; i >= 0; i--)
            if(!vis[i])
                ans = max(ans, prev - v[i]), prev = v[i];
        return ans;
    }
};

// @lc app=leetcode id=2498 lang=cpp