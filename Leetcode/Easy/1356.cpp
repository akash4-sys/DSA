#include "../../headers.h"

// Time Complexity - O(NLogN)
// Space Complexity - O(1)
class Solution
{
public:
    vector<int> sortByBits(vector<int> &v)
    {
        auto comp = [&](auto a, auto b){
            int x = __builtin_popcount(a), y = __builtin_popcount(b);
            return x < y || (x == y && a < b);
        };
        sort(v.begin(), v.end(), comp);
        return v;
    }
};