#include "../../headers.h"

class Solution
{
public:
    int maximumSum(vector<int> &v)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int n : v)
        {
            int sum = 0, a = n;
            for (; n; n /= 10)
                sum += n % 10;
            if (mp.count(sum))
                ans = max(ans, mp[sum] + a);
            mp[sum] = max(mp[sum], a);
        }
        return ans == 0 ? -1 : ans;
    }
};