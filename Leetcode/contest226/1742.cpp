#include "../../headers.h"

class Solution
{
public:
    int countBalls(int l, int r)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (; l <= r; l++)
        {
            int sum = 0;
            for (int n = l; n; n /= 10)
                sum += n % 10;
            ans = max(ans, ++mp[sum]);
        }
        return ans;
    }
};