#include "../../headers.h"

class Solution
{
public:
    int maxOperations(vector<int> &v)
    {
        int ans = 1, s = v[0] + v[1];
        for (int i = 2; i < v.size() - 1; i += 2)
            if (v[i] + v[i + 1] == s)
                ans++;
        return ans;
    }
};