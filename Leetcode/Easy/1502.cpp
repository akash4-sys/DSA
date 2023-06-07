#include "../../headers.h"

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int d = v[1] - v[0];
        for (int i = 2; i < v.size(); i++)
            if (d != v[i] - v[i - 1])
                return 0;
        return 1;
    }
};