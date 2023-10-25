#include "../../headers.h"

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        string ans = s;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
            {
                string r = "";
                for (int j = i, cnt = 0; j < s.size() && cnt < k; j++)
                {
                    cnt += s[j] == '1';
                    r += s[j];
                    if (cnt == k)
                        ans = (ans.size() > r.size()) ? r : min(ans, r);
                }
            }
        return (count(ans.begin(), ans.end(), '1') < k) ? "" : ans;
    }
};