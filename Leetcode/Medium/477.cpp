#include "../../headers.h"

// A bit simplified version
class Solution
{
public:
    int totalHammingDistance(vector<int> &v)
    {
        int ans = 0, n = v.size();
        for(int i = 0; i < 32; i++)
        {
            int c = 0;
            for(int j = 0; j < n; j++)
                c += (v[j] >> i) & 1;
            ans += c * (n - c);
        }
        return ans;
    }
};



class Solution
{
public:
    int totalHammingDistance(vector<int> &v)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int a[2] = {0}, c = 0;
            for (int j = 0; j < v.size(); j++)
            {
                c += v[j] == 0;
                a[v[j] % 2]++;
                v[j] >>= 1;
            }
            ans += a[0] * a[1];
            if (c == v.size())
                break;
        }
        return ans;
    }
};

// @lc app=leetcode id=477 lang=cpp