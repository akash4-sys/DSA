#include "../../headers.h"

// Time Complexity - O(2^N), where N is req.size()
// Space Complexity - O(N)

class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &req)
    {
        int total = 1 << req.size();
        for (int mask = total - 1; mask >= 0; mask--)
        {
            int size = 0, p = 1;
            vector<int> deg(n, 0);
            for (int i = 0; i < req.size(); i++)
                if (mask & (1 << i))
                    deg[req[i][0]]--, deg[req[i][1]]++, size++;
            
            for (auto d : deg)
                if (d) {
                    p = 0;
                    break;
                }
            if (p)
                return size;
        }
        return -1;
    }
};