#include "headers.h"

class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &v)
    {
        vector<int> ans;
        unordered_map<int, int> sf, pf;
        for (int n : v)
            sf[n]++;
        
        for (int n : v)
        {
            pf[n]++;
            sf[n]--;
            if (sf[n] == 0)
                sf.erase(n);
            ans.push_back((int)pf.size() - (int)sf.size());
        }
        return ans;
    }
};