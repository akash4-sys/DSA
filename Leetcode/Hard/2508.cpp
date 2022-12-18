#include "../../headers.h"

class Solution
{
public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        vector<unordered_set<int>> g(n + 1);
        vector<int> odd;
        for (auto e : edges)
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]); 
        
        for (int i = 1; i <= n; i++)
            if(g[i].size() % 2)
                odd.push_back(i);

        if(odd.size() == 2)
            for (int i = 1; i <= n; i++)
                if (!g[odd[0]].count(i) && !g[odd[1]].count(i))
                    return 1;  
        
        if(odd.size() == 4)
            return (!g[odd[0]].count(odd[1]) && !g[odd[2]].count(odd[3]))
                || (!g[odd[0]].count(odd[2]) && !g[odd[1]].count(odd[3]))
                || (!g[odd[0]].count(odd[3]) && !g[odd[1]].count(odd[2]));
        return !odd.size();
    }
};