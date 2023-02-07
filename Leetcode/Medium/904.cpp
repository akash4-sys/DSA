#include "../../headers.h"

class Solution
{
public:
    int totalFruit(vector<int> &v)
    {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        for (; i < v.size(); i++)
        {
            mp[v[i]]++;
            if (mp.size() > 2)
            {
                if (--mp[v[j]] == 0)
                    mp.erase(v[j]); 
                j++;
            }
        }
        return i - j;
    }
};