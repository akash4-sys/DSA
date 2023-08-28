#include "../../headers.h"

class Solution
{
public:
    vector<string> fullJustify(vector<string> &v, int maxWidth)
    {
        vector<string> ans;
        for (int n = v.size(), len, gap, i = 0, j = 0; i < n;)
        {
            for (len = maxWidth; j < n && len >= j - i + v[j].size();)
                len -= v[j++].size();
            
            gap = (j - i == 1) || (j == n) ? 0 : len / (j - i - 1);
            len -= gap * (j - i - 1);

            ans.push_back("");
            while (i < j - 1)
                ans.back() += v[i++] + string(gap + (len-- > 0), ' ');
            ans.back() += v[i++] + string(max(len, 0), ' ');
        }
        return ans;
    }
};