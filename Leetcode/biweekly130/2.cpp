#include "../../headers.h"

class Solution
{
public:
    int maxPointsInsideSquare(vector<vector<int>> &v, string s)
    {
        long long n = v.size(), ans = 0, l = 0, r = 1e9 + 1;
        for (int i = 0; i < n; i++)
            v[i].push_back(i);
        sort(v.begin(), v.end());
        
        while (l <= r)
        {
            int res = 1;
            long long k = (l + r) / 2, cnt = 0, ch[26] = {0}, uq = 0;
            for (int i = 0; i < n; i++)
                if (v[i][0] >= -k && v[i][0] <= k && v[i][1] >= -k && v[i][1] <= k)
                    ++ch[s[v[i][2]] - 'a'] == 1, cnt++;
            
            for (int i = 0; i < 26 && res; i++)
                if (ch[i] > 1)
                    res = 0;
            
            if (res)
                l = k + 1, ans = max(ans, cnt);
            else
                r = k - 1;
        }
        return ans;
    }
};