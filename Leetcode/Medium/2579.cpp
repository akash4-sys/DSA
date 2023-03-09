#include "../../headers.h"

class Solution
{
public:
    long long coloredCells(int n)
    {
        return (1l * n * n) + (1l * (n - 1) * (n - 1));
    }
};


class Solution
{
public:
    long long coloredCells(int n)
    {
        long long ans = 1, cells = 0;
        for (int i = 2; i <= n; i++)
            cells += 4, ans += cells;
        return ans;
    }
};