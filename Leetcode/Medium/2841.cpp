#include "headers.h"

class Solution
{
public:
    long long maxSum(vector<int> &v, int m, int k)
    {
        long long ans = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
            mp[v[i]]++, sum += v[i];
        
        if (mp.size() >= m)
            ans = max(ans, sum);
        for (int i = 1; i <= v.size() - k; i++)
        {
            mp[v[i + k - 1]]++;
            sum += v[i + k - 1] - v[i - 1];
            if (mp[v[i - 1]] == 1)
                mp.erase(v[i - 1]);
            if (mp.size() >= m)
                ans = max(ans, sum);
        }
        return ans;
    }
};