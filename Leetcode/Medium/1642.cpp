#include "../../headers.h"

class Solution
{
public:
    int furthestBuilding(vector<int> &v, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < v.size() - 1; i++)
            if (int req = v[i + 1] - v[i]; req > 0)
            {
                pq.push(req);
                if (pq.size() > ladders)
                    bricks -= pq.top(), pq.pop();
                if (bricks < 0)
                    return i;
            }
        return v.size() - 1;
    }
};