#include "../../headers.h"

class Solution
{
    string findInString(string s, char findC, int &i)
    {
        string r = "";
        while (s[i] != findC)
            r += s[i], i++;
        i++;
        return r;
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> ump;
        for (string s : paths)
        {
            int i = 0;
            string dir = findInString(s, ' ', i);
            while(i <= s.size())
            {
                string fileName = findInString(s, '(', i);
                string content = findInString(s, ')', i);
                ump[content].push_back(dir + '/' + fileName);
                i++;
            }
        }

        for(auto &x: ump)
            if(x.second.size() >= 2)
                ans.push_back(x.second);
        return ans;
    }
};