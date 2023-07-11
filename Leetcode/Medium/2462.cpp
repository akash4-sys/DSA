#include "headers.h"

class Solution
{
public:
    long long totalCost(vector<int> &v, int k, int c)
    {
        using p = pair<int, int>;
        long long ans = 0, n = v.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        
        for(int i = 0; i < c; i++)
            pq.push({v[i], 0});
        for(int i = max((int)n - c, c); i < n; i++)
            pq.push({v[i], 1});

        int i = c, j = n - c - 1;
        while (k--)
        {
            auto [x, flag] = pq.top();
            pq.pop();
            ans += x;
            if (i <= j) {
                if (!flag)
                    pq.push({v[i++], 0});
                else
                    pq.push({v[j--], 1});
            }
        }
        return ans;
    }
};

class Solution
{
public:
    long long totalCost(vector<int> &v, int k, int c)
    {
        long long ans = 0, n = v.size();
        priority_queue<int, vector<int>, greater<int>> f, b;
        vector<int> vis(v.size(), 0);

        for(int i = 0; i < c; i++)
            f.push(v[i]), vis[i] = 1;
        for(int i = n - c; i < n; i++)
            if(!vis[i])
                b.push(v[i]), vis[i] = 1;
        
        int i = c - 1, j = n - c;
        while(k--)
        {
            if(f.empty() && !b.empty())
                ans += b.top(), b.pop();
            else if(b.empty() && !f.empty())
                ans += f.top(), f.pop();
            else if(f.top() <= b.top())
            {
                ans += f.top();
                f.pop();
                if(i + 1 < v.size() && !vis[i + 1])
                    f.push(v[++i]), vis[i] = 1;
            }
            else
            {
                ans += b.top();
                b.pop();
                if(j - 1 >= 0 && !vis[j - 1])
                    b.push(v[--j]), vis[j] = 1;
            }
        }
        return ans;
    }
};


// @lc app=leetcode id=2462 lang=cpp