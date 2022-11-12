#include "../../headers.h"

class Solution
{
    int ans = 0, vis;
public:
    int countArrangement(int n, int p = 1)
    {
        if (n < 4) return n;    //this case can be excluded
        if(p > n) return ans++;
        for(int i = 1; i <= n; i++)
            if(!(vis & (1 << i)) && (i % p == 0 || p % i == 0))
                vis |= (1 << i), countArrangement(n, p + 1), vis ^= (1 << i);
        return ans;
    }
};


class Solution
{
    int vis[16] = {0}, ans = 0;
    int dfs(int n, int p)
    {
        if(p > n)
            return ans++;
        for(int i = 1; i <= n; i++)
            if(!vis[i] && (i % p == 0 || p % i == 0))
                vis[i] = 1, dfs(n, p + 1), vis[i] = 0;
        return ans;
    }
public:
    int countArrangement(int n)
    {
        return (n < 4) ? n : dfs(n, 1);
    }
};

// @lc app=leetcode id=526 lang=cpp