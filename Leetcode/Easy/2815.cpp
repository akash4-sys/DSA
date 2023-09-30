#include "../../headers.h"

class Solution
{
public:
    int maxSum(vector<int> &v)
    {
        int ans = -1, cnt[10] = {0};
        for (int n : v)
        {
            string s = to_string(n);
            int m = *max_element(s.begin(), s.end()) - '0';
            if (cnt[m])
                ans = max(ans, cnt[m] + n);
            cnt[m] = max(cnt[m], n);
        }
        return ans;
    }
};