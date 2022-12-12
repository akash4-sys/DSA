#include "headers.h"

class Solution
{
public:
    int longestSquareStreak(vector<int> &v)
    {
        int ans = -1, n = v.size();
        sort(v.begin(), v.end());
        vector<int> vis(n, 0);
        unordered_map<long long, int> mp;

        for(int i = 0; i < n; i++)
            mp[v[i]] = i;

        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                continue;
            long long l = 1, x = v[i] * v[i];
            while(mp.count(x))
            {
                vis[mp[x]] = 1;
                x = v[mp[x]] * v[mp[x]];
                l++;
            }
            int a = l == 1? -1 : l;
            ans = max(ans, a);
            if(a == 5) return 5; // idea from hint
        }

        return ans;
    }
};