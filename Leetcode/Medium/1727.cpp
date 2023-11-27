#include "../../headers.h"

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector v(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
            for (int i = 0, cnt = 0; i < m; i++)
                v[i][j] = cnt = mat[i][j] ? cnt + 1 : 0;
        
        for (int i = 0; i < m; i++) {
            sort(v[i].begin(), v[i].end(), greater<int>());
            for (int j = 0; j < n; j++)
                ans = max(ans, v[i][j] * (j + 1));
        }
        return ans;
    }
};