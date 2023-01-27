#include "../../headers.h"

// Bezeout's Identity

class Solution 
{
public:
    bool isGoodArray(vector<int>& v)
    {
        int g = v[0];
        for (int n : v)
            g = gcd(g, n);
        return g == 1;
    }
};

class Solution 
{
public:
    bool isGoodArray(vector<int>& v)
    {
        if (v.size() == 1)
            return v[0] == 1;
        
        int g = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            g = gcd(g, v[i]);
            if (g == 1)
                return 1;
        }
        return 0;
    }
};