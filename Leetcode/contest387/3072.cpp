#include "../../headers.h"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> a = {nums[0]}, b = {nums[1]};
        ordered_set s1, s2;
        s2.insert(nums[1]), s1.insert(nums[0]);
        for (int i = 2; i < n; i++)
        {
            int x = s1.size() - s1.order_of_key(nums[i] + 1);
            int y = s2.size() - s2.order_of_key(nums[i] + 1);
            if (x > y)
                s1.insert(nums[i]), a.push_back(nums[i]);
            else if (x < y)
                s2.insert(nums[i]), b.push_back(nums[i]);
            else
            {
                if (s1.size() <= s2.size())
                    s1.insert(nums[i]), a.push_back(nums[i]);
                else
                    s2.insert(nums[i]), b.push_back(nums[i]);
            }
        }
        copy(b.begin(), b.end(), back_inserter(a));
        return a;
    }
};