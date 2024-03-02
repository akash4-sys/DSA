#include "../../headers.h"

class Solution
{
public:
    bool isPossibleToSplit(vector<int> &v)
    {
        unordered_map<int, int> mp;
        for (int a : v)
            if (++mp[a] > 2)
                return 0;
        return 1;
    }
};