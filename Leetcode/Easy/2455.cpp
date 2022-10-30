#include "headers.h"

class Solution
{
public:
    int averageValue(vector<int> &v)
    {
        int sum = 0, c = 0;
        for(int n: v)
            if(n % 2 == 0 && n % 3 == 0)
                sum += n, c++;
        return sum ? sum/c : 0;
    }
};