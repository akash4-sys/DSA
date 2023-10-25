#include "../../headers.h"

class Solution
{
    bool canCreate(int m, vector<int> &v, vector<int> &st, vector<int> &c, long long x)
    {
        long long cost = 0;
        for (int i = 0; i < v.size(); i++)
            cost += (max((v[i] * x * 1LL) - st[i], 0LL) * c[i] * 1LL);
        return cost <= m;
    }

public:
    int maxNumberOfAlloys(int n, int k, int m, vector<vector<int>> &v, vector<int> &st, vector<int> &c)
    {
        int min_cost = *min_element(c.begin(), c.end()), ans = 0;
        for (auto &cmp : v)
        {
            int l = 0, r = (m / min_cost) + 10;
            while (l <= r) {
                long long mid = (l + r) / 2;
                canCreate(m, cmp, st, c, mid) ? l = mid + 1 : r = mid - 1;
            }
            ans = max(ans, l - 1);
        }
        return ans;
    }
};