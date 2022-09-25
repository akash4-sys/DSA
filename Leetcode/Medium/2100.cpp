#include "../../headers.h"

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &v, int k)
    {
        int n = v.size();
        vector<int> inc(n, 0), dec(n, 0), ans;
        
        for (int i = 1; i < n; i++)
            if (v[i] <= v[i - 1])
                dec[i] = dec[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (v[i] <= v[i + 1])
                inc[i] = inc[i + 1] + 1;

        for (int i = k; i < n - k; i++)
            if (dec[i] >= k && inc[i] >= k)
                ans.push_back(i);
        return ans;
    }
};