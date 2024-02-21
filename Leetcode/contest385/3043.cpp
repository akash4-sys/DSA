#include "../../headers.h"

class Solution
{
public:
    int longestCommonPrefix(vector<int> &a, vector<int> &b)
    {
        int ans = 0;
        unordered_set<string> st;
        for (int x : a)
        {
            string s = to_string(x), r = "";
            for (int i = 0; i < s.size(); i++)
                r += s[i], st.insert(r);
        }

        for (int x : b)
        {
            string s = to_string(x), r = "";
            for (int i = 0; i < s.size(); i++)
            {
                r += s[i];
                if (st.count(r))
                    ans = max(ans, (int)r.size());
            }
        }
        return ans;
    }
};