#include "../../headers.h"

class Solution
{
public:
    int change(int n, vector<int> &coins)
    {
        vector<int> v(n + 1, n + 10);
        v[0] = 0;

        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int c : coins)
            {
                if (i >= c)
                {
                    v[i] = min(v[i], 1 + v[i - c]);
                    if(i == n)
                        ans++;
                }
            }
        return ans;
    }
};