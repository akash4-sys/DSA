#include "../../headers.h"

class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& v)
    {
        unordered_map<int, int> mp;
        for (int n : v)
            mp[n]++;
        
        int x = mp.begin()->second;
        for (auto &[n, c]: mp)
            if (x != c)
                return 0;
        return x > 1;
    }
};