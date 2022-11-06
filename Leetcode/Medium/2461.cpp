#include "headers.h"

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &v, int k)
    {
        long long ans = 0, sum = 0;
        unordered_map<int, int> m;
        
        for(int i = 0; i < k; i++)
            m[v[i]]++, sum += v[i];
        if(m.size() == k)
            ans = max(ans, sum);

        for(int i = 1; i <= v.size() - k; i++)
        {
            sum = (sum - v[i - 1]) + v[i + k - 1];
            m[v[i - 1]]--;
            m[v[i + k - 1]]++;
            if(m[v[i - 1]] == 0)
                m.erase(v[i - 1]);
            if(m.size() == k)
                ans = max(ans, sum);
        }
        return ans;
    }
};