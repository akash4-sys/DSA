#include "../../headers.h"

class Solution
{
public:
    vector<int> majorityElement(vector<int> &v)
    {
        int a = -1, b = -1, ca = 0, cb = 0;
        for (int n : v)
            if (n == a)
                ca++;
            else if (n == b)
                cb++;
            else if (!ca)
                a = n, ca = 1;
            else if (!cb)
                b = n, cb = 1;
            else
                ca--, cb--;

        ca = cb = 0;
        for (int n : v)
            ca += a == n, cb += b == n && a != n;
        
        vector<int> ans;
        if (ca > v.size() / 3)
            ans.push_back(a);
        if (cb > v.size() / 3)
            ans.push_back(b);
        return ans;
    }
};