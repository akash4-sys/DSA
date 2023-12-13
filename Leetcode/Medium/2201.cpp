#include "../../headers.h"

class Solution
{
public:
    int digArtifacts(int n, vector<vector<int>> &v, vector<vector<int>> &dig)
    {
        vector m(n, vector<int>(n, 0));
        for (auto &d : dig)
            m[d[0]][d[1]] = 1;
        
        int ans = 0;
        for (auto &a : v)
        {
            int res = 1;
            for (int i = a[0]; i <= a[2] && res; i++)
                for (int j = a[1]; j <= a[3] && res; j++)
                    if (!m[i][j])
                        res = 0;
            ans += res;
        }
        return ans;
    }
};