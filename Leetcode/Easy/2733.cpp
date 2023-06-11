#include "headers.h"

class Solution
{
public:
    int findNonMinOrMax(vector<int> &v)
    {
        if (v.size() <= 2)
            return -1;
        
        int x = max({v[0], v[1], v[2]}), y = min({v[0], v[1], v[2]});
        for (int i = 0; i < 3; i++)
            if (x != v[i] && y != v[i])
                return v[i];
        return -1;
    }
};


class Solution
{
public:
    int findNonMinOrMax(vector<int> &v)
    {
        if (v.size() <= 2)
            return -1;

        int x = 0, y = INT_MAX;
        for (int n : v)
            x = max(x, n), y = min(y, n);
            
        for (int n : v)
            if (n != x && n != y)
                return n;
        return -1;
    }
};