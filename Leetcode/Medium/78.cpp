#include "../../headers.h"

// Recursive
class Solution
{
    vector<vector<int>> ans;
    vector<int> sub;

public:
    vector<vector<int>> subsets(vector<int> &nums, int i = 0)
    {
        ans.push_back(sub);
        for (int j = i; j < nums.size(); j++)
        {
            sub.push_back(nums[j]);
            subsets(nums, j + 1);
            sub.pop_back();
        }
        return ans;
    }
};

// Iterative

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans = {{}};
        for (int n : nums)
        {
            int sz = ans.size();
            for (int i = 0; i < sz; i++)
            {
                ans.push_back(ans[i]);
                ans[i].push_back(n);
            }
        }
        return ans;
    }
};


// Bit Manipulation

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> ans(p);
        for(int i = 0; i < p; i++)
        {
            for(int j = 0; j < n; j++)
                if((i >> j) & 1)
                    ans[i].push_back(nums[j]);
        }
        return ans;
    }
};