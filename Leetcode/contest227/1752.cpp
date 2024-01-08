#include "../../headers.h"

class Solution
{
public:
    bool check(vector<int> &v)
    {
        vector<int> vs = v;
        sort(vs.begin(), vs.end());
        for (int i = 0; i <= v.size(); i++)
        {
            if (v == vs)
                return 1;
            int a = v[0];
            v.erase(v.begin());
            v.push_back(a);
        }
        return 0;
    }
};