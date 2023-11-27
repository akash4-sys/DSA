#include "../../headers.h"

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &v, char x)
    {
        vector<int> ans;
        for (int i = 0; i < v.size(); i++)
            if (v[i].find(x) != string::npos)
                ans.push_back(i);
        return ans;
    }
};