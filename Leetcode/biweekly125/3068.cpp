#include "../../headers.h"

class Solution {
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long ans = 0, cnt = 0, d = LLONG_MAX;
        for (long long a : nums)
        {
            long long b = a ^ k;
            cnt += (b >= a);
            d = min(d, abs(a - b));
            ans += max(a, b);
        }
        return cnt % 2 ? ans - d : ans;
    }
};