#include "../../headers.h"

class Solution
{
public:
    int countPairs(vector<vector<int>> &v, int k)
    {
        int ans = 0;
        map<pair<int, int>, int> mp;
        for (auto &c : v)
        {
            for (int i = 0; i <= k; i++)
            {
                int x = i ^ c[0], y = (k - i) ^ c[1];
                if (mp.count({x, y}))
                    ans += mp[{x, y}];
            }
            mp[{c[0], c[1]}]++;
        }
        return ans;
    }
};