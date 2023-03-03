#include "../../headers.h"

class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int>& v)
    {
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0, n = v.size(), j = n / 2; i != n / 2 && j < n; j++)
            if (v[i] * 2 <= v[j])
                i++, ans += 2;
        return ans;
    }
};