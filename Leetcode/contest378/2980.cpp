#include "../../headers.h"

class Solution
{
public:
    bool hasTrailingZeros(vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
            {
                int x = v[i] | v[j];
                if (x & 1)
                    return 1;
            }
        return 0;
    }
};