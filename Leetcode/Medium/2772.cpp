#include "../headers.h"

class Solution
{
public:
    bool checkArray(vector<int> &v, int k)
    {
        int sub = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (sub > v[i])
                return 0;
            v[i] -= sub;
            sub += v[i];
            if (i - k + 1 >= 0)
                sub -= v[i - k + 1];
        }
        return !sub;
    }
};