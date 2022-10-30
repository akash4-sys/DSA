#include "headers.h"

class Solution
{
    bool check(string &q, vector<string> &d)
    {
        for(string s: d)
        {
            int edits = 0;
            for(int i = 0; i < s.size(); i++)
                if(s[i] != q[i])
                    edits++;
            if(edits <= 2)
                return 1;
        }
        return 0;
    }

public:
    vector<string> twoEditWords(vector<string> &q, vector<string> &d)
    {
        vector<string> ans;
        for(string s: q)
            if(check(s, d))
                ans.push_back(s);
        return ans;
    }
};