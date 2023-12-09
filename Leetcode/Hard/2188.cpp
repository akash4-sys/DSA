#include "../../headers.h"

class Solution
{
    int dp[1001];
    long long rec(vector<long long> &minTime, int time, int k)
    {
        if (k == 0)
            return -time;
        if (dp[k] != -1)
            return dp[k];
        
        long long res = INT_MAX;
        for (int laps = 1; laps <= min(k, 18); laps++)
            res = min(res, rec(minTime, time, k - laps) + time + minTime[laps]);
        return dp[k] = res;
    }

public:
    int minimumFinishTime(vector<vector<int>> &v, int time, int k)
    {
        int n = v.size(), ans = 0;
        vector<long long> minTime(k + 1, INT_MAX);
        for (auto &t : v)
        {
            long long f = t[0], r = 1, totTime = 0;
            for (int lap = 1; lap <= k && f * r < t[0] + time; lap++)
            {
                totTime += (r * f);
                minTime[lap] = min(minTime[lap], totTime);
                r *= t[1];
            }
        }
        memset(dp, -1, sizeof(dp));
        return rec(minTime, time, k);
    }
};