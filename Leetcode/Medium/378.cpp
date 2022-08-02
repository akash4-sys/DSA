#include "../../headers.h"

class Solution
{
    typedef tuple<int, int, int> Item;
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        priority_queue<Item, vector<Item>, greater<>> q;
        for (int i = 0; i < n; ++i)
            q.emplace(matrix[0][i], 0, i);
        while (--k)
        {
            auto [o, x, y] = q.top();
            q.pop();
            if (x + 1 < n)
                q.emplace(matrix[x + 1][y], x + 1, y);
        }
        return get<0>(q.top());
    }
};