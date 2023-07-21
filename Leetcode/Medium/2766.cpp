#include "headers.h"

class Solution
{
public:
    vector<int> relocateMarbles(vector<int> &v, vector<int> &moveFrom, vector<int> &moveTo)
    {
        set<int> s(v.begin(), v.end());
        for (int i = 0; i < moveFrom.size(); i++)
        {
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
        return {s.begin(), s.end()};
    }
};