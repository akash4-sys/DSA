#include "headers.h"

class Solution
{
public:
    long long countQuadruplets(vector<int> &v)
    {
        int n = v.size();
        vector<vector<int>> pi(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= n; j++)
                pi[j][i] = pi[j][i - 1] + (v[i - 1] < j);
            
        long long ans = 0;
        for (int j = 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (v[k] < v[j])
                {
                    long long i = (n - v[j]) - (k - pi[v[j]][k + 1]);
                    long long l = pi[v[k]][j + 1];
                    ans += (i * l);
                }
        return ans;
    }
};


class Solution
{
public:
    long long countQuadruplets(vector<int> &v)
    {
        int n = v.size();
        vector<vector<int>> pi(n, vector<int>(n, 0)), pl = pi;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                pl[i][j] = pl[i][j - 1] + (v[i] < v[j]);

        for (int i = n - 1; i >= 0; i--)
            for (int j = i - 1; j >= 0; j--)
                pi[j][i] = pi[j + 1][i] + (v[j] < v[i]);

        long long ans = 0;
        for (int j = 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (v[k] < v[j])
                    ans += ((pi[0][k] - pi[j][k]) * (pl[j][n - 1] - pl[j][k]));
        return ans;
    }
};