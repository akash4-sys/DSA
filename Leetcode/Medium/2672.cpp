#include "headers.h"

class Solution
{
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &qrs)
    {
        vector<int> ans, col(n, 0);
        int c = 0;
        for (auto q : qrs)
        {
            int i = q[0];
            c -= (i - 1 >= 0 && col[i] && col[i] == col[i - 1]);
            c -= (i + 1 < n && col[i] && col[i] == col[i + 1]);
            col[i] = q[1];
            c += (i - 1 >= 0 && col[i] == col[i - 1]);
            c += (i + 1 < n && col[i] == col[i + 1]);
            ans.push_back(c);
        }
        return ans;
    }
};