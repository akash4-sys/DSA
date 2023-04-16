#include "headers.h"

class Solution
{
    bool isPrime(int n)
    {
        if (n == 1)
            return 0;
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            if (n % i == 0)
                return 0;
        return 1;
    }

public:
    int diagonalPrime(vector<vector<int>> &v)
    {
        int ans = 0, n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (isPrime(v[i][i]))
                ans = max(ans, v[i][i]);
            if (isPrime(v[i][n - i - 1]))
                ans = max(ans, v[i][n - i - 1]);
        }
        return ans;
    }
};