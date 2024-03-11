#include "../../headers.h"

class Solution
{
public:
    vector<int> resultArray(vector<int> &v)
    {
        vector<int> a = {v[0]}, b = {v[1]};
        for (int i = 2; i < v.size(); i++)
            if (a.back() > b.back())
                a.push_back(v[i]);
            else
                b.push_back(v[i]);
        copy(b.begin(), b.end(), back_inserter(a));
        return a;
    }
};