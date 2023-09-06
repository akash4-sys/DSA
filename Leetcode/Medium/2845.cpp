#include "../../headers.h"

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &v, int mod, int k)
    {
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp = {{0, 1}};
        for (int n : v)
        {
            (sum += n % mod == k) %= mod;
            ans += mp[(sum - k + mod) % mod];
            mp[sum]++;
        }
        return ans;
    }
};


// @lc app=leetcode id=2845 lang=cpp