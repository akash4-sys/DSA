#include "../../headers.h"

class Solution
{
public:
    long long countSubarrays(vector<int> &v, int k)
    {
        long long ans = 0, mx = *max_element(v.begin(), v.end()), i = 0, cnt = 0;
        for (int n : v)
        {
            cnt += n == mx;
            while (cnt >= k)
                cnt -= v[i++] == mx;
            ans += i;
        }
        return ans;
    }
};