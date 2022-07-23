#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k)
    {
        vector<vector<int>> res;

        if (nums.size() == start)
            return res;
            
        long long avg = target / k;

        if (nums[start] > avg || avg > nums.back())
            return res;

        if (k == 2)
            return twoSum(nums, target, start);

        for (int i = start; i < nums.size(); ++i)
        {
            if (i == start || nums[i - 1] != nums[i])
            {
                for (auto &v : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(v), end(v));
                }
            }
        }
        return res;
    }

    vector<vector<int>> twoSum(vector<int> &nums, long long target, int start)
    {
        vector<vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;

        while (lo < hi)
        {
            int curr_sum = nums[lo] + nums[hi];
            if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1]))
            {
                ++lo;
            }
            else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
            {
                --hi;
            }
            else
            {
                res.push_back({nums[lo++], nums[hi--]});
            }
        }

        return res;
    }
};



// Another half assed approach

class Solution
{
public:
    vector<vector<int>> ans;

    void recurse(vector<int> &nums, int target, int i, int s, int e, int be)
    {
        if (s > e || s > be)
            return;
        int sum = nums[i] + nums[e] + nums[be] + nums[s];
        if (sum > target)
        {
            if (e - be == 2)
                recurse(nums, target, i, s, e - 1, be);
            else
                recurse(nums, target, i, s, e, be - 1);
        }
        else if (sum < target)
        {
            recurse(nums, target, i, s + 1, e, be);
        }
        else
            ans.push_back({nums[i], nums[e], nums[be], nums[s]});
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int s = i + 1, e = n - 1, be = n - 2;
            recurse(nums, target, i, s, e, be);
        }
        return ans;
    }
};