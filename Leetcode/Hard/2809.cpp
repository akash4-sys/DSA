#include "../../headers.h"

class Solution
{
    vector<vector<int>> v;

    int rec(int x, int a, int b, int i, int t)
    {
        if ((t * b) + a <= x)
            return t;
        if (t == v.size())
            return INT_MAX;
        
        int res = INT_MAX;
        for (int j = i; j < v.size(); j++)
            res = min(res, rec(x, a - v[i][1], b - v[i][0], j + 1, t + 1));
        return res;
    }

public:
    int minimumTime(vector<int> &a, vector<int> &b, int x)
    {
        int p = 0, q = 0;
        for (int i = 0; i < a.size(); i++)
        {
            p += a[i];
            q += b[i];
            v.push_back({b[i], a[i]});
        }
        sort(v.begin(), v.end());
        return rec(x, p, q, 0, 0);
    }
};