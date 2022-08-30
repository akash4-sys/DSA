#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int ans = nums[0];
        deque<int> dq = {nums[0]};
        vector<int> v = {nums[0]};

        for (int i = 1; i < nums.size(); i++)
        {
            if (i > k && dq.front() == v[i - k - 1])
                dq.pop_front();
            v.push_back(max(nums[i], dq.front() + nums[i]));
            
            // monotonic queue
            while (!dq.empty() && dq.back() < v.back())
                dq.pop_back();
            dq.push_back(v.back());
            ans = max(ans, v.back());
        }
        return ans;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int ans = nums[0];
        deque<int> dq = {nums[0]};
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > k && dq.front() == nums[i - k - 1])
                dq.pop_front();
            nums[i] = max(nums[i], dq.front() + nums[i]);
            // monotonic queue
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};