#include "../../headers.h"

class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        sort(tasks.begin(), tasks.end(), greater<int>());
        sort(processorTime.begin(), processorTime.end());

        int ans = 0, i = 0;
        for (int n : processorTime)
        {
            int maxTime = 0;
            for (int j = i; j < i + 4; j++)
            {
                maxTime = max(maxTime, tasks[j]);
            }
            i += 4;
            ans = max(ans, n + maxTime);
        }
        return ans;
    }
};