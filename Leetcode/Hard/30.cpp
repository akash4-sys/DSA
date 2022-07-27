#include "../../headers.h"

class Solution
{
public:

    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        int wlen = words[0].length(), n = words.size();
        int sublen = n * wlen;

        if (sublen > s.length())
            return ans;

        unordered_map<string, int> wcounts;
        for (string r : words)
            wcounts[r]++;

        for (int i = 0; i <= s.length() - sublen; i++)
        {
            unordered_map<string, int> wfound;
           for(int j = 0; j < n; j++)
            {
                int k = (wlen)*j + i;
                string r = s.substr(k, wlen);
                if(!wcounts[r])
                    break;
                
                wfound[r]++;
                if(wfound[r] > wcounts[r])
                    break;
                
                if(n == j+1)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};