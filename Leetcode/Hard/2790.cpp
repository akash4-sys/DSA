#include "../../headers.h"

class Solution
{
public:
    int maxIncreasingGroups(vector<int> &v)
    {
        sort(v.begin(), v.end());
        long long sum = 0, g = 0;
        for (int i = 0; i < v.size(); i++)
            if ((sum += v[i]) >= (g + 1) * (g + 2) / 2)
                g++;
        return g;
    }
};


class Solution
{
public:
    int maxIncreasingGroups(vector<int> &v)
    {
        sort(v.begin(), v.end(), greater<int>());
        int l = 1, r = v.size();
        while (l <= r)
        {
            int mid = (l + r) / 2, extra = 0, height = mid;
            for (int i = 0; i < v.size(); i++)
            {
                extra = max(height + extra - v[i], 0);
                height -= height ? 1 : 0;
            }
            extra ? r = mid - 1 : l = mid + 1;
        }
        return l - 1;
    }
};