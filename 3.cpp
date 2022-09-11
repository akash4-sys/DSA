#include "headers.h"

class Solution
{
public:
    int minGroups(vector<vector<int>> &vi)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < vi.size(); i++)
            v.push_back({vi[i][0], vi[i][1]});
        sort(v.rbegin(), v.rend());
        
        int cnt = vi.size(), st = 0, ans = 0;
        vector<int> vis(cnt, 0);
        while(cnt--)
        {
            if(vis[st])
                ++st;
            int x = v[st].first;
            vis[st] = 1;
            for(int i = st + 1; i < vi.size(); i++)
                if(!vis[i] && x > v[i].first && x > v[i].second)
                {
                    cnt -= 1; 
                    vis[i] = 1;
                    x = v[i].first;
                }
            st += 1;
            ans++;
        }
        return ans;
    }
};