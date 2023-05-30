#include "headers.h"

class Solution
{
public:
    int minNumber(vector<int> &a, vector<int> &b)
    {
        int x[10] = {0}, p = 11, q = 11;
        for (int n : a)
            x[n] = 1, p = min(n, p);
        for (int n : b)
            x[n]++, q = min(n, q);
        for (int i = 0; i < 10; i++)
            if (x[i] == 2)
                return i;
        return min((p * 10) + q, (q * 10) + p);
    }
};