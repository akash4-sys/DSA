#include "headers.h"

class Solution
{
public:
    int isWinner(vector<int> &a, vector<int> &b)
    {
        int x = 0, y = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int p = 1, q = 1;
            if ((i - 1 >= 0 && a[i - 1] == 10) || (i - 2 >= 0 && a[i - 2] == 10))
                p = 2;
            if ((i - 1 >= 0 && b[i - 1] == 10) || (i - 2 >= 0 && b[i - 2] == 10))
                q = 2;
            x += (p * a[i]);
            y += (q * b[i]);
        }
        if (x == y)
            return 0;
        return x > y ? 1 : 2;
    }
};