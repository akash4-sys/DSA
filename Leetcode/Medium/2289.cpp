#include "../../headers.h"

class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        vector<int> v(n), st;
        for (int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && nums[i] > nums[st.back()])
            {
                v[i] = max(++v[i], v[st.back()]);
                st.pop_back();
                ans = max(ans, v[i]);
            }
            st.push_back(i);
        }
        return ans;
    }
};