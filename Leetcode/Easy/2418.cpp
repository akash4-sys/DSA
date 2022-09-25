#include "headers.h"

// Time complexity O(log N)
// Space complexity O(N)
class Solution
{
public:
    vector<string> sortPeople(vector<string> &nm, vector<int> &h)
    {
        vector<string> ans;
        map<int, string, greater<int>> mp;
        for(int i = 0; i < nm.size(); i++)
            mp[h[i]] = nm[i];
        for(auto x: mp)
            ans.push_back(x.second);
        return ans;
    }
};