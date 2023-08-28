#include "../../headers.h"

class Solution
{
public:
    int longestValidSubstring(string s, vector<string> &v)
    {
        int ans = 0, len = 0;
        unordered_set<string> st;
        for (string &r : v)
            st.insert(r), len = max(len, (int)r.size());
        
        for (int i = s.size() - 1, en = s.size(); en > ans && i >= 0; i--)
        {
            string r = "";
            for (int j = i; j < en && j - i < len; j++)
            {
                r += s[j];
                if (st.count(r)) {
                    en = j;
                    break;
                }
            }
            ans = max(ans, en - i);
        }
        return ans;
    }
};