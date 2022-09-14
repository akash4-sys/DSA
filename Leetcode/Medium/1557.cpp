#include "../../headers.h"

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> mp(n, 0), ans;
        for(auto e: edges)
            mp[e[1]]++;

        for(int i=0; i<mp.size(); i++)
            if(!mp[i])
                ans.push_back(i);
        return ans;
    }
};