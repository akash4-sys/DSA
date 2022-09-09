#include "../../headers.h"

class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &p)
    {
        int ans = 0, m = 0;
        sort(p.begin(), p.end(), [](const auto &x, const auto &y){
            return x[0] == y[0] ? x[1] < y[1] : x[0] > y[0];
        });
        for(auto &x: p)
            ans += x[1] < m, m = max(m, x[1]);
        return ans;
    }
};