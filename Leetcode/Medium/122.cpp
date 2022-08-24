#include "../../headers.h"

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int ans = 0, buy = INT_MAX, sell, i = 1, n = p.size();
        while (i < n)
        {
            for (buy = p[i - 1]; i < n && p[i] < buy; i++)
                buy = p[i];

            if (i >= n)
                return ans;

            for (sell = p[i]; i < n && p[i] >= sell; i++)
                sell = p[i];

            ans += sell - buy;
        }
        return ans;
    }
};

// Simplified way

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int ans = 0;
        for(int i = 1; i < p.size(); i++)
            if(p[i] > p[i-1])
                ans += (p[i] - p[i-1]);
        return ans;
    }
};