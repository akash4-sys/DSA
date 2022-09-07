#include "../../headers.h"

class Solution
{
public:
    int maxPoints(vector<vector<int>> &p)
    {
        if(p.size() <= 2)
            return p.size();
        
        int ans = 0;
        for(int i = 0; i < p.size(); i++)
        {
            unordered_map<double, int> mp;
            int dup = 0;
            double slope = 0.0;
            for(int j = 0; j < p.size(); j++)
            {
                int dx = p[j][0] - p[i][0];
                int dy = p[j][1] - p[i][1];
                if(!dy && !dx)
                {
                    dup++;
                    continue;
                }
                slope = dx ? dy * 1.0 / dx : INT_MAX;
                mp[slope]++;
            }

            if(!mp.size())
                ans = dup;
            else
                for(auto x: mp)
                    ans = max(ans, x.second + dup);
        }
        return ans;
    }
};