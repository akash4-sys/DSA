#include "headers.h"

class Solution 
{
public:
    int captureForts(vector<int>& v)
    {
        int ans = 0;
        for (int i = 0, j = 0; i < v.size(); i++)
            if(v[i])
            {
                if(v[j] == -v[i])
                    ans = max(ans, i - j - 1);
                j = i;
            }
        return ans;
    }
};