#include "../../headers.h"

class Solution
{
public:
    int maximumStrongPairXor(vector<int> &v)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
                if (abs(v[i] - v[j]) <= min(v[i], v[j]))
                    ans = max(ans, v[i] ^ v[j]);
        return ans;
    }
};