#include "../../headers.h"

class Solution
{
public:
    string simplifyPath(string s)
    {
        string ans = "", r = "";
        vector<string> v;
        stringstream ss(s);
        while (getline(ss, r, '/'))
            if (r != "" && r != ".")
            {
                if (r == ".." && v.size())
                    v.pop_back();
                else if (r != "..")
                    v.push_back(r);
            }
        
        for (string str : v)
            ans += "/" + str;
        return ans.size() ? ans : "/";
    }
};