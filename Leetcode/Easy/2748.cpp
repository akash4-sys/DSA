#include "headers.h"

class Solution
{
public:
    int countBeautifulPairs(vector<int> &v)
    {
        int ans = 0, cnt[10] = {0};
        for (int i = 0; i < v.size(); i++)
        {
            for (int n = 1; n < 10; n++)
                if (gcd(n, v[i] % 10) == 1)
                    ans += cnt[n];
            for (; v[i] >= 10; v[i] /= 10);
            cnt[v[i]]++;
        }
        return ans;
    }
};


class Solution
{
public:
    int countBeautifulPairs(vector<int> &v)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
            {
                string s = to_string(v[i]);
                int x = s[0] - '0', y = v[j] % 10;
                if (gcd(x, y) == 1)
                    ans++;
            }
        return ans;
    }
};