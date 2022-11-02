#include "../../headers.h"

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        if(s.size() < 10)
            return {};
        vector<string> ans;
        unordered_map<string, int> mp;
        for(int i = 0; i < s.size() - 9; i++)
            mp[s.substr(i, 10)]++;
        for(auto &[r, c]: mp)
            if(c > 1)
                ans.push_back(r);
        return ans;
    }
};