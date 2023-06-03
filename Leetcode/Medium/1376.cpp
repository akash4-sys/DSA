#include "../../headers.h"

class Solution
{
public:
    int numOfMinutes(int n, int root, vector<int> &par, vector<int> &t)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!t[i])
            {
                int sum = 0;
                for (int u = i; u != -1; u = par[u])
                    sum += t[u];
                ans = max(ans, sum);
            }
        return ans;
    }
};