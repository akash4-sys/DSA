#include "../../headers.h"

class Solution
{
public:
    int prefixCount(vector<string> &v, string p)
    {
        int n = p.size(), ans = 0;
        for (auto &s : v)
            ans += (s.size() >= n && s.substr(0, n) == p);
        return ans;
    }
};