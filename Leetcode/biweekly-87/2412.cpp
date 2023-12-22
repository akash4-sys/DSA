#include "../../headers.h"

class Solution
{
public:
    long long minimumMoney(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [&](auto &a, auto &b) {
            if (a[0] < a[1])
                return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        long long cash = 0, ans = 0;
        for (auto &t : v)
        {
            if (cash < t[0])
            {
                ans += t[0] - cash;
                cash += t[0] - cash;
            }
            cash = cash - t[0] + t[1];
        }
        return ans;
    }
};