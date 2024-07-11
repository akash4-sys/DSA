#include "../../headers.h"

class Solution
{
public:
    int duplicateNumbersXOR(vector<int> &v)
    {
        int fq[51], x = 0;
        for (int &a : v)
            fq[a]++;
        
        for (int i = 1; i <= 50; i++)
            if (fq[i] == 2)
                x ^= i;
        return x;
    }
};