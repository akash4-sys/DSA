#include "../../headers.h"

class Solution
{
public:
    long long taskSchedulerII(vector<int> &v, int k)
    {
        long long day = 0;
        unordered_map<int, long long> mp;
        for (int a : v)
            if (mp.count(a))
                mp[a] = day = max(day, mp[a] + k) + 1;
            else
                mp[a] = ++day;
        return day;
    }
};