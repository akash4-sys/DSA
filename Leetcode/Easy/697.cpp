#include "../../headers.h"

class Solution
{
public:
    int findShortestSubArray(vector<int> &v)
    {
        unordered_map<int, int> mp;
        int hf = 0, ans = INT_MAX;
        for (int n : v)
            mp[n]++, hf = max(hf, mp[n]);
        
        for (auto [n, f] : mp)
            if (f == hf)
            {
                int i = 0, j = v.size() - 1;
                for (; i < v.size() && v[i] != n; i++);
                for (; j >= 0 && v[j] != n; j--);
                ans = min(ans, j - i + 1);
            }
        return ans;
    }
};