#include "../../headers.h"

class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &v, vector<int> &qrs, int x)
    {
        vector<int> ans, occ;
        for (int i = 0; i < v.size(); i++)
            if (v[i] == x)
                occ.push_back(i);
        
        for (int &q : qrs)
            if (occ.size() < q)
                ans.push_back(-1);
            else
                ans.push_back(occ[q - 1]);
        return ans;
    }
};