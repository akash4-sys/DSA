#include "headers.h"

class Solution
{
public:
    int findMinimumTime(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        int ans = 0, time[2001] = {0};
        for (auto &a : v)
        {
            for (int j = a[0]; j <= a[1]; j++)
                a[2] -= time[j];
            if (a[2] <= 0)
                continue;
            ans += a[2];
            for (int j = a[1]; a[2]; j--)
                a[2] -= !time[j], time[j] = 1;
        }
        return ans;
    }
};