#include "../../headers.h"

class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& v, int k)
    {
        for (int i = v.size() - 1; i >= 0 && k; i--)
        {
            v[i] += k;
            k = v[i] / 10;
            v[i] %= 10;
        }

        for (; k; k /= 10)
            v.insert(v.begin(), k % 10);
        return v;
    }
};


class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& v, int k)
    {
        int c = 0;
        for (int i = v.size() - 1; i >= 0; i--, k /= 10)
        {
            int x = k ? k % 10 : 0;
            int n = v[i] + x + c;
            v[i] = n % 10;
            c = n / 10;
        }

        c += k;
        for (; c; c /= 10)
            v.insert(v.begin(), c % 10);
        return v;
    }
};


// @lc app=leetcode id=989 lang=cpp