#include "headers.h"

#define vv vector<vector<int>>
#define vec vector<int>
#define pb push_back
#define p pair<int,int>
#define vp vector<p>
#define pp pop_back
#define a array<int, 3>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vec maxPoints(vv &grid, vec &q)
    {
        int n = grid.size(), m = grid[0].size(), points = 0;
        vec ans(q.size());
        vp sq;
        for(int i = 0; i < q.size(); i++)
            sq.pb({q[i], i});
        
        sort(sq.begin(), sq.end());
        priority_queue<a, vector<a>, greater<a>> pq;
        vv vis(n, vec(m, 0));       // instead of using visited even grid can be used
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        for(auto [qr, idx] : sq)
        {
            while(!pq.empty() && pq.top()[0] < qr)
            {
                int i = pq.top()[1], j = pq.top()[2];
                pq.pop();
                points++;
                for(auto [dx, dy] : dirs)
                {
                    int x = i + dx, y = j + dy;
                    if(x >= 0 && y >= 0 && x < n && y < m && !vis[x][y])
                        vis[x][y] = 1, pq.push({grid[x][y], x, y});
                }
            }
            ans[idx] = points;
        }
        return ans;
    }
};