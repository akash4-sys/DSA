#include "../../headers.h"

class Solution
{
    vector<int> zAlgo(string &s)
    {
        int n = s.size(), x = 0, y = 0;
        vector<int> zArray(n);
        for (int i = 1; i < n; i++)
        {
            zArray[i] = max(0, min(zArray[i - x], y - i + 1));
            while (i + zArray[i] < n && s[zArray[i]] == s[i + zArray[i]])
                x = i, y = i + zArray[i], zArray[i]++;
        }
        return zArray;
    }

public:
    int minimumTimeToInitialState(string &s, int k)
    {
        int ans = 1;
        auto z = zAlgo(s);
        for (; ans * k < s.size(); ans++)
            if (z[ans * k] >= s.size() - (ans * k))
                break;
        return ans;
    }
};