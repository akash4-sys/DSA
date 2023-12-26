#include "../../headers.h"

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &v, int k)
    {
        sort(v.begin(), v.end(), [&] (auto &a, auto &b) {
            return a[1] > b[1] || (a[1] == b[1] && a[0] > b[0]);
        });

        int ans = 0, box = 0;
        for (auto &b : v)
        {
            ans += (min(k - box, b[0]) * b[1]);
            box += min(k - box, b[0]);
        }
        return ans;
    }
};