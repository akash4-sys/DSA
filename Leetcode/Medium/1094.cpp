#include "../../headers.h"

class Solution
{
public:
    bool carPooling(vector<vector<int>> &lines, int cap)
    {
        map<int, int> mp;
        for (auto l : lines)
            mp[l[1]] += l[0], mp[l[2]] -= l[0];
        for (auto [x, w] : mp)
            if ((cap -= w) < 0)
                return false;
        return true;
    }
};