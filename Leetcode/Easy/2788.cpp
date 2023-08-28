#include "headers.h"

class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &v, char x)
    {
        vector<string> ans;
        for (auto s : v)
        {
            string r = "";
            for (char c : s)
            {
                if (c == x) {
                    if (r != "")
                        ans.push_back(r), r = "";
                }
                else
                    r += c;
            }
            if (r != "")
                ans.push_back(r);
        }
        return ans;
    }
};