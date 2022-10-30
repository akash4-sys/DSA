#include "../../headers.h"

class Solution
{
public:
    int countTriplets(vector<int> &v)
    {
        int ans = 0, x = 0;
        unordered_map<int, int> c = {{0, 1}}, t;
        for(int i = 0; i < v.size(); i++)
        {
            x ^= v[i];
            ans += c[x]++ * i - t[x];
            t[x] += i + 1;
        }
        return ans;
    }
};