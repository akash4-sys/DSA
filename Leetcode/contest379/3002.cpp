#include "../../headers.h"

class Solution
{
public:
    int maximumSetSize(vector<int> &a, vector<int> &b)
    {
        unordered_set<int> st_a(a.begin(), a.end()), st_b(b.begin(), b.end()), common;
        for (int x : st_a)
            if (st_b.count(x))
                common.insert(x);
        int n = a.size(), na = st_a.size(), nb = st_b.size(), c = common.size();
        return min(n, min(na - c, n / 2) + min(nb - c, n / 2) + c);
    }
};