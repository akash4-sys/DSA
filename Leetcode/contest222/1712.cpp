#include "../../headers.h"

class Solution
{
public:
    int waysToSplit(vector<int> &v)
    {
        int mod = 1e9 + 7, ans = 0, n = v.size();
        vector<int> pf;
        for (int &a : v)
            pf.push_back(pf.size() ? pf.back() + a : a);

        for (int i = 0, j = 0, k = 0; i < n - 2; i++)
        {
            j = max(i + 1, j);
            while (j < n - 1 && pf[j] < pf[i] * 2)
                j++;

            k = max(k, j);
            while (k < n - 1 && pf[k] - pf[i] <= pf[n - 1] - pf[k])
                k++;
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};