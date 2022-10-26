#include "../../headers.h"

class Solution
{
public:
    bool checkSubarraySum(vector<int> &v, int k)
    {
        unordered_map<int, int> ump = {{0, -1}};
        for(int i = 0, sum = 0; i < v.size(); i++)
        {
            sum += v[i];
            if(ump.count(sum % k) && i - ump[sum % k] > 1)
                    return true;
            ump.insert({sum % k, i});
        }
        return false;
    }
};


// @lc app=leetcode id=523 lang=cpp