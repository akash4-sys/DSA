#include "../../headers.h"

class Solution
{
public:
    bool validPartition(vector<int> &v)
    {
        bool dp[4] = {1, 0, v[0] == v[1], 0};
        for (int i = 2; i < v.size(); ++i)
        {
            bool two = v[i] == v[i - 1];
            bool three = (two && v[i] == v[i - 2]) || (v[i] - 1 == v[i - 1] && v[i] - 2 == v[i - 2]);
            dp[(i + 1) % 4] = (dp[(i - 1) % 4] && two) || (dp[(i - 2) % 4] && three);
        }
        return dp[v.size() % 4];
    }
};



class Solution
{
    int n, dp[100001];
    bool rec(vector<int> &v, int i)
    {
        if (i >= n)
            return 1;
        if (dp[i] != -1)
            return dp[i];

        int res = 0;
        if (i + 1 < n && v[i] == v[i + 1])
            res |= rec(v, i + 2);
        if (i + 2 < n && ((v[i] == v[i + 1] && v[i] == v[i + 2]) || (v[i + 1] - v[i] == 1 && v[i + 2] - v[i + 1] == 1)))
            res |= rec(v, i + 3);
        return dp[i] = res;
    }

public:
    bool validPartition(vector<int> &v)
    {
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return rec(v, 0);
    }
};