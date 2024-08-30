#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                v.push_back({grid[i][j], i, j});
        
        long long ans = 0;
        sort(v.begin(), v.end(), greater<vector<int>>());
        for (int x = 0; x < 3; x++)
        {
            long long sum = v[x][0], cnt = 1;
            set<int> row = {v[x][1]}, col = {v[x][2]};
            for (int k = 1; k < n * m && cnt < 3; k++)
                if (!row.count(v[k][1]) && !col.count(v[k][2])) {
                    row.insert(v[k][1]);
                    col.insert(v[k][2]);
                    sum += v[k][0];
                    cnt++;
                }
            ans = max(ans, sum);
        }
        return ans;
    }    
};