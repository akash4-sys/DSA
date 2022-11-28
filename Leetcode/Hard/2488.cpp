#include "headers.h"

class Solution
{
public:
    int countSubarrays(vector<int> &v, int k)
    {
        unordered_map<int, int> ump;
        int x = find(begin(v), end(v), k) - v.begin(), ans = 0;
        for(int i = x, b = 0; i < v.size(); i++)
        {
            b += v[i] == k ? 0 : v[i] < k ? -1 : 1;
            ump[b]++;
        }

        for(int i = x, b = 0; i >= 0; i--)
        {
            b += v[i] == k ? 0 : v[i] < k ? -1 : 1;
            ans += ump.count(-b) ? ump[-b] : 0;
            ans += ump.count(-b + 1) ? ump[-b + 1] : 0;
        }
        return ans;
    }
};