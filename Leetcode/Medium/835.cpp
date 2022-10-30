#include "../../headers.h"

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &a, vector<vector<int>> &b)
    {
        int ans = 0, n = a.size();
        vector<int> x, y;
        unordered_map<int, int> c;
        for(int i = 0; i < n * n; i++)
            if(a[i / n][i % n] == 1)
                x.push_back(i / n * 100 + i % n);
        for(int i = 0; i < n * n; i++)
            if(b[i / n][i % n] == 1)
                y.push_back(i / n * 100 + i % n);
        for(int i: x)
            for(int j: y)
                c[i - j]++;
        for(auto [z, n]: c)
            ans = max(ans, n);
        return ans;
    }
};