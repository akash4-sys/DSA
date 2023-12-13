#include "../../headers.h"

class Solution
{
public:
    long long minimumRemoval(vector<int> &v)
    {
        long long ans = LLONG_MAX, n = v.size();
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            if (sum >= (n - i) * v[i] * 1LL)
                ans = min(ans, sum - ((n - i) * v[i] * 1LL));
        return ans;
    }
};