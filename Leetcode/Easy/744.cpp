#include "../../headers.h"

class Solution
{
public:
    char nextGreatestLetter(vector<char> &v, char t)
    {
        auto it = upper_bound(v.begin(), v.end(), t) - v.begin();
        return it >= v.size() ? v[0] : v[it];
    }
};