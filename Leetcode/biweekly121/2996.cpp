#include "../../headers.h"

class Solution
{
public:
    int missingInteger(vector<int> &v)
    {
        unordered_map<int, int> mp;
        for (int a : v)
            mp[a]++;
        
        int sum = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] != v[i - 1] + 1)
                break;
            sum += v[i];
        }

        while (!mp.count(sum))
            sum++;
        return sum;
    }
};