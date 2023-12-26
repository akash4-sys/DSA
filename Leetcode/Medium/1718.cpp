#include "../../headers.h"

class Solution
{
    vector<int> dfs(vector<int> &v, int n, int p, int mask)
    {
        if (p == v.size())
            return v;
        if (v[p] != 0)
            return dfs(v, n, p + 1, mask);
        for (int i = n; i >= 1; --i)
        {
            int dist = i == 1 ? 0 : i;
            if (!(mask & (1 << i)) && dist + p < v.size() && v[dist + p] == 0)
            {
                v[p] = v[p + dist] = i;
                auto res = dfs(v, n, p + 1, mask | (1 << i));
                if (!res.empty())
                    return res;
                v[p] = v[p + dist] = 0;
            }
        }
        return {};
    }

public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> v((n - 1) * 2 + 1);
        return dfs(v, n, 0, 0);
    }
};