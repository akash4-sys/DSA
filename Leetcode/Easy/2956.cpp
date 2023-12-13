#include "../../headers.h"

class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &a, vector<int> &b)
    {
        int x = 0, y = 0;
        for (int p : a)
        {
            for (int q : b)
                if (q == p)
                {
                    x++;
                    break;
                }
        }

        for (int p : b)
        {
            for (int q : a)
                if (q == p)
                {
                    y++;
                    break;
                }
        }
        return {x, y};
    }
};