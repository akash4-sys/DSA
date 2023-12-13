#include "../../headers.h"

class Solution
{
    vector<int> freq(vector<int> &v, int it)
    {
        int a = 0, b = 0;
        unordered_map<int, int> mp;
        for (int i = it; i < v.size(); i += 2)
            if (++mp[v[i]] >= mp[a]) {
                b = v[i] != a ? a : b;
                a = v[i];
            }
            else if (mp[v[i]] > mp[b])
                b = v[i];
        return {a, mp[a], mp[b]};
    }

public:
    int minimumOperations(vector<int> &v)
    {
        auto odd = freq(v, 1), even = freq(v, 0);
        return v.size() - (odd[0] != even[0] ? odd[1] + even[1] : max(odd[1] + even[2], odd[2] + even[1]));
    }
};