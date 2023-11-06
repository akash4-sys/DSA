#include "../../headers.h"

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> ind(n, 0);
        for (auto &e : edges)
            ind[e[1]]++;
        
        int ans = -1, cnt = 0;
        for (int i = 0; i < ind.size(); i++)
            if (!ind[i])
                ans = i, cnt++;
        return cnt > 1 ? -1 : ans;
    }
};