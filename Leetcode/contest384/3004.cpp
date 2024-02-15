#include "../../headers.h"

class Solution
{
public:
    int countMatchingSubarrays(vector<int> &v, vector<int> &p)
    {
        int ans = 0, n = v.size(), m = p.size();
        for (int i = 0; i < n - m; i++)
        {
            int f = 1;
            for (int k = 0; k < m && f; k++)
                if (p[k] == 1 && v[i + k + 1] <= v[i + k])
                    f = 0;
                else if (p[k] == 0 && v[i + k + 1] != v[i + k])
                    f = 0;
                else if (p[k] == -1 && v[i + k + 1] >= v[i + k])
                    f = 0;
            ans += f;
        }
        return ans;
    }
};