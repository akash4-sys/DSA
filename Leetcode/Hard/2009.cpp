#include "../../headers.h"

#define all(v) v.begin(), v.end()

class Solution
{
public:
    int minOperations(vector<int> &v)
    {
        long long n = v.size(), ans = n;
        sort(v.begin(), v.end());
        v.resize(distance(v.begin(), unique(v.begin(), v.end())));
        for (int i = 0; i < v.size(); i++)
            ans = min(ans, i + n - (upper_bound(all(v), v[i] + n - 1) - v.begin()));
        return ans;
    }
};