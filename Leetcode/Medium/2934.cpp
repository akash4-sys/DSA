#include "../../headers.h"

class Solution
{
    int calc(vector<int> &a, vector<int> &b)
    {
        int x = a.back(), y = b.back(), ans = 0;
        for (int i = a.size() - 2; i >= 0; i--)
        {
            int n1 = a[i], n2 = b[i];
            if (max(x, n1) != x || max(y, n2) != y)
                swap(n1, n2), ans++;
            if (max(x, n1) != x || max(y, n2) != y)
                return 1001;
        }
        return ans;
    }

public:
    int minOperations(vector<int> &a, vector<int> &b)
    {
        int ans = calc(a, b);
        swap(a.back(), b.back());
        ans = min(ans, calc(a, b) + 1);
        return ans >= 1001 ? -1 : ans;
    }
};