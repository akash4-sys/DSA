#include "../../headers.h"

class Solution
{
public:
    vector<int> decode(vector<int> &v, int f)
    {
        v.insert(v.begin(), f);
        for(int i = 1; i < v.size(); i++)
            v[i] ^= v[i - 1];
        return v;
    }
};