#include "../../headers.h"

class Solution
{
    long long p(long long a, long long b, long long mod)
    {
        long long res = 1;
        for (a %= mod; b > 0; b >>= 1)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
        }
        return res % mod;
    }

public:
    vector<int> getGoodIndices(vector<vector<int>> &v, int t)
    {
        vector<int> ans;
        for (int i = 0; i < v.size(); i++)
            if (p(p(v[i][0], v[i][1], 10), v[i][2], v[i][3]) == t)
                ans.push_back(i);
        return ans;
    }
};