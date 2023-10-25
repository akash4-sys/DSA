#include "../../headers.h"

class Solution
{
    int isValid(unordered_map<int, int> &mp, int gs)
    {
        int res = 0, k = gs + 1;
        for (auto [n, c] : mp)
        {
            int cnt = c / k, r = c % k;
            if (r > 0 && r < gs)
            {
                int rq = gs - r;
                if (cnt < rq)
                    return 0;
                cnt = (cnt - rq) + (r + k * rq) / gs;
                r = 0;
            }
            res += cnt + !!r;
        }
        return res;
    }

public:
    int minGroupsForValidAssignment(vector<int> &v)
    {
        unordered_map<int, int> mp;
        for (int n : v)
            mp[n]++;
        
        int mn = min_element(begin(mp), end(mp), [](auto &a, auto &b){
            return a.second < b.second; })->second;
        
        for (int g = mn; g >= 1; g--)
        {
            int ans = isValid(mp, g);
            if (ans)
                return ans;
        }
        return v.size();
    }
};