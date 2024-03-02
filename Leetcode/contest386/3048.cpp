#include "../../headers.h"

class Solution
{
    bool isPossible(vector<int> &v, vector<int> &c, int k)
    {
        int op = 0, n = v.size(), marked = 0;
        vector<int> vis(n + 1, 0);
        for (int i = k - 1; i >= 0; i--)
            if (!vis[c[i]])
            {
                op += v[c[i] - 1];
                vis[c[i]] = 1;
                marked++;
            }
            else
                op = max(op - 1, 0);
        return marked == n && op == 0;
    }

public:
    int earliestSecondToMarkIndices(vector<int> &v, vector<int> &c)
    {
        long long l = accumulate(v.begin(), v.end(), 0LL) + v.size();
        int m = c.size(), r = m;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            isPossible(v, c, mid) ? r = mid - 1 : l = mid + 1;
        }
        return l > m ? -1 : l;
    }
};