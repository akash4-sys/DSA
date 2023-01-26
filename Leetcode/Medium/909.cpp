#include "../../headers.h"

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &m)
    {
        int n = m.size() * m.size();
        vector<pair<int, int>> mp(n + 1); 
        for (int i = m.size() - 1, k = 1, lr = 1; i >= 0; i--)
        {
            for (int j = 0; j < m.size() && lr; j++)
                mp[k++] = {i, j};
            for (int j = m.size() - 1; j >= 0 && !lr; j--)
                mp[k++] = {i, j};
            lr ^= 1;
        }
        
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty())
        {
            auto [curr, moves] = q.front();
            q.pop();
            if(curr == n)
                return moves;

            for (int i = curr + 1; i <= min(n, curr + 6); i++)
            {
                auto [x, y] = mp[i];
                if (m[x][y] != INT_MAX)
                {
                    int next = m[x][y] != -1 ? m[x][y] : i;
                    m[x][y] = INT_MAX;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};