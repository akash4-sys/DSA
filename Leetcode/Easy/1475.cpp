#include "../../headers.h"

class Solution
{
public:
    vector<int> finalPrices(vector<int> &p)
    {
        vector<int> v;
        for(int i = 0; i < p.size(); i++)
        {
            while(v.size() && p[v.back()] >= p[i])
            {
                p[v.back()] -= p[i];
                v.pop_back();
            }
            v.push_back(i);
        }
        return p;
    }
};