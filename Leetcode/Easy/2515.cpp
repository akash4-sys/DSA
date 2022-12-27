#include "headers.h"

class Solution
{
public:
    int closetTarget(vector<string> &v, string s, int st)
    {
        int result = INT_MAX, n = v.size();
        for (int i = 0; i < n; i++)
            if (v[i] == s)
                result = min({result, abs(st - i), (n - abs(st - i))});
        return result == INT_MAX ? -1 : result;
    }
}; 