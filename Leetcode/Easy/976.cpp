#include "../../headers.h"

class Solution
{
public:
    int largestPerimeter(vector<int> &v)
    {
        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i > 1; i--)
            if (v[i] < v[i - 1] + v[i - 2])
                return v[i] + v[i - 1] + v[i - 2];
        return 0;
    }
};