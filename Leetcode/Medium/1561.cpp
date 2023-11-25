#include "../../headers.h"

class Solution
{
public:
    int maxCoins(vector<int> &v)
    {
        int n = v.size(), ans = 0;
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 1, j = 1; j <= n / 3; j++, i += 2)
            ans += v[i];
        return ans;
    }
};