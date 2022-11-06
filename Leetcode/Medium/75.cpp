#include "../../headers.h"

class Solution
{
public:
    void sortColors(vector<int> &v)
    {
        int l = 0, r = v.size() - 1, i = 0;
        while(i <= r)
            if(!v[i])
                swap(v[i++], v[l++]);
            else if(v[i] == 1)
                i++;
            else swap(v[i], v[r--]);
    }
};


class Solution
{
public:
    void sortColors(vector<int> &v)
    {
        int count[3] = {0}, i = 0, j = 0;
        for(int n: v)
            count[n]++;
        while(i < v.size())
            if(count[j]-- > 0)
                v[i++] = j;
            else j++;
    }
};

// @lc app=leetcode id=75 lang=cpp