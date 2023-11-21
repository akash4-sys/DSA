#include "../../headers.h"

class Solution
{
public:
    int reductionOperations(vector<int> &v)
    {
        sort(v.begin(), v.end(), greater<int>());
        int ans = 0;
        for (int i = 1; i < v.size(); i++)
            if (v[i - 1] != v[i])
                ans += i;
        return ans;
    }
};


class Solution
{
public:
    int reductionOperations(vector<int> &v)
    {
        map<int, int> mp;
        for (int &n : v)
            mp[n]++;
        
        int ans = 0, f = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
            f += it->second, ans += f;
        return ans - f;
    }
};