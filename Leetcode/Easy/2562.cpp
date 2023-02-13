#include "headers.h"

class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &v)
    {
        long long ans = v.size() % 2 ? v[v.size() / 2] : 0;
        for (int i = 0, j = v.size() - 1; i < j; i++, j--)
            ans += stoll(to_string(v[i]) + to_string(v[j]));
        return ans;
    }
};