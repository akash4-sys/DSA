#include "../../headers.h"

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &edges)
    {
        long long ans = 0;
        vector<int> city(n, 0);
        for (auto e : edges)
            city[e[0]]++, city[e[1]]++;

        sort(city.begin(), city.end());
        for (int i = 0; i < n; i++)
            ans += city[i] * (i + 1);
            
        return ans;
    }
};