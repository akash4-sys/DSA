#include "../../headers.h"

class Solution 
{
public:
    int jump(vector<int>& v) 
    {
        int ans = 0, currIdx = 0, maxJump = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            maxJump = max(maxJump, v[i] + i);
            if (currIdx == i)
                currIdx = maxJump, ans++;
        }
        return ans;
    }
};