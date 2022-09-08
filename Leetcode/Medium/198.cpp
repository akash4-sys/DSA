#include "../../headers.h"

// TLE
class Solution
{
public:
    int rob(vector<int> &v, int i = 0)
    {
        return i < v.size() ? max(rob(v, i + 1), rob(v, i + 2) + v[i]) : 0;
    }
};

// DP Bottom UP

class Solution
{
public:
    int rob(vector<int> &v, int i = 0)
    {
        int last = 0, lastLast = 0, sum = 0;
        for (int n : v)
        {
            sum = max(last, n + lastLast);
            lastLast = last;
            last = sum;
        }
        return sum;
    }
};