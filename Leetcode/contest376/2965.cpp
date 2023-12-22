#include "../../headers.h"

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &m)
    {
        int n = m.size() * m.size(), a, b;
        vector<int> v(n + 1, 0);
        for (auto &r : m)
            for (int x : r)
                v[x]++;
        
        for (int i = 1; i <= n; i++)
            if (v[i] == 2)
                a = i;
            else if (!v[i])
                b = i;
        return {a, b};
    }
};