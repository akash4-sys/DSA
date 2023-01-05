#include "../../headers.h"

class Solution
{
public:
    int minDeletionSize(vector<string> &v)
    {
        int ans = 0;
        for (int j = 0; j < v[0].size(); j++)
            for (int i = 1; i < v.size(); i++)
                if (v[i][j] < v[i - 1][j])
                {
                    ans++;
                    break;
                }
        return ans;
    }
};