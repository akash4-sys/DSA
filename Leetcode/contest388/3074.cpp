#include "../../headers.h"

class Solution
{
public:
    int minimumBoxes(vector<int> &a, vector<int> &c)
    {
        sort(c.begin(), c.end(), greater<int>());
        int apples = accumulate(a.begin(), a.end(), 0), ans = 0;
        for (int n : c)
        {
            if (!apples)
                break;
            if (n >= apples)
                n -= apples, apples = 0;
            else
                apples -= n;
            ans++;
        }
        return ans;
    }
};