#include "headers.h"

class Solution
{
    unordered_map<char, int> mp = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
public:
    int vowelStrings(vector<string> &v, int l, int r)
    {
        int ans = 0;
        for (; l <= r; l++)
            ans += (mp.count(v[l][0]) && mp.count(v[l].back()));
        return ans;
    }
};