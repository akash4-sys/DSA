#include "../../headers.h"

class Solution
{
public:
    int triangularSum(vector<int> &v)
    {
        while (v.size() != 1)
        {
            for (int i = 1, n = v.size(); i < n; i++)
                v[i - 1] = ((v[i - 1] + v[i]) % 10);
            v.pop_back();
        }
        return v[0];
    }
};