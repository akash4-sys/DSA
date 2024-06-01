#include "../../headers.h"

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> roots, height(n, 0), root_height(n, 0);
        vector<vector<int>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        function<int(int, int)> dfs = [&](int u, int par) -> int {
            int maxSubTreeH = 0;
            for (int v : g[u])
                if (v != par)
                    maxSubTreeH = max(maxSubTreeH, dfs(v, u));
            height[u] = maxSubTreeH;
            return maxSubTreeH + 1;
        };

        int h = dfs(0, -1);
        for (int i = 1; i < n; i++) {
            int r = h * 2 - height[i];
            root_height[i] = r + max(height[i] - r, 0);
        }

        int minH = *min_element(root_height.begin(), root_height.end());
        for (int i = 0; i < n; i++)
            if (root_height[i] == minH)
                roots.push_back(i);
        return roots;
    }
};