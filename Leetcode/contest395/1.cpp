#include "../../headers.h"

class Solution
{
public:
    int addedInteger(vector<int> &a, vector<int> &b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a[0] - b[0];
    }
};