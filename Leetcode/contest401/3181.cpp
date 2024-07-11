#include "../../headers.h"

class Solution
{
    unordered_map<int, int> mp;
    int rec(vector<int> &v, int sum)
    {
        if (mp.count(sum))
            return mp[sum];
        
        int res = 0, j = upper_bound(v.begin(), v.end(), sum) - v.begin();
        for (int i = j; i < v.size(); i++)
            res = max(res, rec(v, sum + v[i]));
        return mp[sum] = max(res, sum);
    }
    
public:
    int maxTotalReward(vector<int> &v)
    {
        sort(v.begin(), v.end());
        return rec(v, 0);
    }
};