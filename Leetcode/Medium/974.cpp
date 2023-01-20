#include "../../headers.h"

class Solution
{
public:
    int subarraysDivByK(vector<int> &v, int k)
    {
        int ans = 0, sum = 0;
        vector<int> mp(k, 0);
        mp[0] = 1;
        for (int n : v)
        {
            sum = (sum + (n % k) + k) % k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};



// Time Complexity - O(N^2)
// Space Complexity - O(1)
// TLE

class Solution
{
public:
    int subarraysDivByK(vector<int> &v, int k)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i, sum = 0; j < v.size(); j++)
                sum += v[j], ans += sum % k == 0;
        return ans;
    }
};

// @lc app=leetcode id=974 lang=cpp