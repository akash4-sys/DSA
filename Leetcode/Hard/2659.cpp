#include "headers.h"

class Solution
{
public:
    long long countOperationsToEmptyArray(vector<int> &v)
    {
        long long ans = 0, n = v.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j){
            return v[i] < v[j];
        });

        for (int i = 1; i < n; i++)
            if (id[i] < id[i - 1])
                ans += (n - i);
        return ans + n;
    }
};