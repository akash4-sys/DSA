#include "headers.h"

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        int i = 0, t = 1;
        while(!mp.count(i))
        {
            mp[i] = 1;
            i = (i + (t * (k - 1))) % n;
            t++;
        }

        for (int i = 0; i < n; i++)
            if (!mp.count(i))
                ans.push_back(i + 1);
        return ans;
    }
};