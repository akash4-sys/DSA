#include "../../headers.h"

// O(N^2) approach
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int d = nums[i + 1] - nums[i];
            for (int j = i + 2; j < nums.size(); j++)
            {
                if (nums[j] - nums[j - 1] != d)
                    break;
                ans++;
            }
        }
        return ans;
    }
};



// O(N) Approach

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &v)
    {
        int ans = 0, p = v[1] - v[0], cnt = 0;
        for (int i = 1; i < v.size() - 1; ++i)
        {
            int d = v[i + 1] - v[i];
            if(p == d)
                cnt++;
            else
                p = d, cnt = 0;
            ans += cnt;
        }
        return ans;
    }
};