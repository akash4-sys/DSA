#include "../../headers.h"

class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &v)
    {
        vector<int> ans;
        for (int n : v)
        {
            while (1)
            {
                int g = gcd(ans.empty() ? 1 : ans.back(), n);
                if (g == 1)
                    break;
                n = lcm(n, ans.back());
                ans.pop_back();
            }
            ans.push_back(n);
        }
        return ans;
    }
};