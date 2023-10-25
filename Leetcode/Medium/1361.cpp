#include "../../headers.h"

class Solution
{
    int nodeCnt(vector<int> &l, vector<int> &r, int u)
    {
        if (u == -1)
            return 0;
        return nodeCnt(l, r, l[u]) + nodeCnt(l, r, r[u]) + 1;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int> &l, vector<int> &r)
    {
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (l[i] != -1)
                indeg[l[i]]++;
            if (r[i] != -1)
                indeg[r[i]]++;
        }

        int cnt = 0, root = -1;
        for (int i = 0; i < n; i++)
        {
            if (!indeg[i])
                cnt++, root = i;
            if (indeg[i] > 1)
                return 0;
        }
        return cnt == 1 && nodeCnt(l, r, root) == n;
    }
};