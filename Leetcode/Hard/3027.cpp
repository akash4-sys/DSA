#include "../../headers.h"

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] >= b[1]);
        });

        int ans = 0, n = v.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1, y = INT_MIN; j < n; j++)
                if (v[i][1] >= v[j][1] && y < v[j][1])
                    ans++, y = v[j][1];
        return ans;
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(1)

class Solution
{
    bool check(int x1, int y1, int x2, int y2, int x, int y)
    {
        return (x >= x1 && x <= x2 && y <= y1 && y >= y2);
    }

public:
    int numberOfPairs(vector<vector<int>> &v)
    {
        int n = v.size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (v[i][0] <= v[j][0] && v[i][1] >= v[j][1] && j != i)
                {
                    int flag = 1;
                    for (int k = 0; k < n && flag; k++)
                        if (k != i && k != j)
                            if (check(v[i][0], v[i][1], v[j][0], v[j][1], v[k][0], v[k][1]))
                                flag = 0;
                    ans += flag;
                }
        return ans;
    }
};