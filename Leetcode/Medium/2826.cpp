#include "../../headers.h"

class Solution
{
public:
    int minimumOperations(vector<int> &v)
    {
        int ans = v.size();
        for (int i = 0; i <= v.size(); i++)
            for (int j = i; j <= v.size(); j++)
            {
                int curr = 0;
                for (int k = 0; k < v.size(); k++)
                    if (k < i)
                        curr += v[k] != 1;
                    else if (k < j)
                        curr += v[k] != 2;
                    else
                        curr += v[k] != 3;
                ans = min(ans, curr);
            }
        return ans;
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(N)

class Solution
{
    int dp[101][4];
    int rec(vector<int> &v, int i, int p)
    {
        if (i == v.size())
            return 0;

        int res = 101;
        for (int j = p; j <= 3; j++)
            res = min(res, rec(v, i + 1, j) + (j != v[i]));
        return dp[i][p] = res;
    }

public:
    int minimumOperations(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, 1);
    }
};