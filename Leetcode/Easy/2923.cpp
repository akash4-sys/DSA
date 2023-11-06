#include "../../headers.h"

class Solution
{
public:
    int findChampion(vector<vector<int>> &g)
    {
        int n = g.size();
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] && i != j)
                    ind[j]++;
        
        int ans = -1, cnt = 0;
        for (int i = 0; i < ind.size(); i++)
            if (!ind[i])
                ans = i, cnt++;
        return cnt > 1 ? -1 : ans;
    }
};