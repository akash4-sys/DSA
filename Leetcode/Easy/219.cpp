#include "../../headers.h"

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &v, int k)
    {
        unordered_map<int, int> ump;
        for (int i = 0; i < v.size(); i++)
        {
            if (ump.count(v[i]) && abs(ump[v[i]] - i) <= k)
                return true;
            ump[v[i]] = i;
        }
        return false;
    }
};