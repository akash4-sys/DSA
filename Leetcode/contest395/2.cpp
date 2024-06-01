#include "../../headers.h"

class Solution
{
public:
    int minimumAddedInteger(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> mpa, mpb;
        for (int &x : a)
            mpa[x]++;
        for (int &x : b)
            mpb[x]++;
        
        for (int x = -1001; x < 1001; x++)
        {
            int f = 1;
            for (auto [n, c] : mpb)
                if (mpa[n - x] < c)
                    f = 0;
            if (f)
                return x;
        }
        return INT_MIN;
    }
};