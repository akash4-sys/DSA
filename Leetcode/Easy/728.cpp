#include "../../headers.h"

class Solution
{
public:
    vector<int> selfDividingNumbers(int l, int r)
    {
        vector<int> ans;
        for (; l <= r; l++)
        {
            int ok = 1;
            for (int n = l; n && ok; n /= 10)
                ok = (n % 10 && !(l % (n % 10)));
            if (ok)
                ans.push_back(l);
        }
        return ans;
    }
};