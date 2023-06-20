#include "../../headers.h"

class Solution
{
public:
    vector<int> getAverages(vector<int> &v, int k)
    {
        int n = v.size(), sum = 0;
        vector<int> pf(n, 0), ans(n, -1);
        for (int i = 0; i < n; i++)
            pf[i] = sum += v[i];
        
        if (k < n && 2 * k < n)
            ans[k] = pf[k * 2] / ((k * 2) + 1);
            
        for (int i = k + 1; i + k < n; i++)
            ans[i] = (pf[i + k] - pf[i - k - 1]) / ((k * 2) + 1);
        return ans;
    }
};