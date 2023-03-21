#include "../../headers.h"

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &v, int n)
    {
        for (int i = 0; i < v.size(); i++)
            if (!v[i] && (!i || !v[i - 1]) && (i == v.size() - 1 || !v[i + 1]))
                v[i] = 1, n--;
        return n <= 0;
    }
};