#include "../../headers.h"

class Solution
{
    int dirs[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
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
    int mostFrequentPrime(vector<vector<int>> &v)
    {
        map<int, int> mp;
        int n = v.size(), m = v[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (auto &[dx, dy] : dirs)
                    for (int a = 0, x = i, y = j; min(x, y) >= 0 && x < n && y < m; x += dx, y += dy)
                        a = (a * 10) + v[x][y], mp[a]++;
        
        int ans = -1, f = 0;
        for (auto &[a, c] : mp)
            if (a > 10 && isPrime(a)) {
                if (c > f)
                    f = c, ans = a;
                else if (c == f)
                    ans = max(ans, a);
            }
        return ans;
    }
};