#include "../../headers.h"

class Solution
{
public:
    int maximumScore(vector<int> &v, int k)
    {
        vector<int> l(k), r;
        for (int i = k - 1, mn = INT_MAX; i >= 0; i--)
            mn = min(mn, v[i]), l[i] = mn;
        
        for (int i = k + 1, mn = INT_MAX; i < v.size(); i++)
            mn = min(mn, v[i]), r.push_back(mn);
        
        reverse(r.begin(), r.end());
        int ans = 0;
        for (int x = 0; x <= v[k]; x++)
        {
            int i = lower_bound(l.begin(), l.end(), x) - l.begin();
            int j = r.size() - (lower_bound(r.begin(), r.end(), x) - r.begin());
            ans = max(ans, ((j + k) - i + 1) * x);
        }
        return ans;
    }
};