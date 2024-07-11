#include "../../headers.h"

class Solution {
public:
    int numberOfChild(int n, int k)
    {
        int i = 0;
        for (int x = 1; k--; i += x)
        {
            if (i == n - 1)
                x = -1;
            else if (i == 0)
                x = 1;
        }
        return i;
    }
};