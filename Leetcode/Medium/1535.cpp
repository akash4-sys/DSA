#include "../../headers.h"

class Solution
{
public:
    int getWinner(vector<int> &v, int k)
    {
        int cnt = 0, mx = 0, p = -1;
        for (int l = 0, r = 1; max(l, r) < v.size(); r++)
        {
            mx = max({mx, v[l], v[r]});
            if (v[l] < v[r])
                l = r;
            p = p == v[l] ? cnt++ : cnt = 1, p = v[l];
            if (cnt == k)
                return v[l];
        }
        return mx;
    }
};