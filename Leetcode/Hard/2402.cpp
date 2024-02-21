#include "../../headers.h"

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        vector<long long> cnt(n, 0), endTime(n, 0);

        int m = v.size(), idx = 0, x = 0;
        for (int i = 0; i < m; i++)
        {
            long long minEndTime = LLONG_MAX, k = 0;
            for (int j = 0; j < n; j++)
            {
                if (endTime[j] <= v[i][0])
                    endTime[j] = 0;
                if (endTime[j] < minEndTime)
                    minEndTime = endTime[j], k = j;
            }
            endTime[k] = minEndTime ? endTime[k] + (v[i][1] - v[i][0]) : v[i][1];
            cnt[k]++;
        }

        for (int i = 0; i < n; i++)
            if (cnt[i] > x)
                x = cnt[i], idx = i;
        return idx;
    }
};